#include "BinTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "Queue.h"

void Swap(BTNode** pLeft, BTNode** pright) {
	BTNode* pTemp = *pLeft;
	*pLeft = *pright;
	*pright = pTemp;
}

void Mirror(BTNode* pRoot) {
	if (pRoot) {
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}
void MirrorNor(BTNode* pRoot) {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q)) {
		BTNode* pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);

		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);
		QueuePop(&q);
	}
}
