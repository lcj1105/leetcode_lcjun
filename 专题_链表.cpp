
struct ListNode
{
    int m_nKey;
    ListNode * m_pNext;
};


// 1. 求单链表中结点的个数

size_t GetListLength(ListNode *pHead){
	if( pHead == NULL )
		return NULL;
	ListNode *pNode = pHead;
	size_t count = 0;
	while(pNode != NULL){
		++count;
		pNode = pNode->m_pNext; 
	}
	return count;
}


// 2 . 将单链表反转

ListNode * ReverseList(ListNode *pHead){
	if( pHead == NULL || pHead->m_pNext == NULL )
		return pHead;
	ListNode *pNode = pHead;
	ListNode *reverseNode = NULL;
	while(pNode != NULL){
		ListNode *pTemp = pNode;
		pNode = pNode->m_pNext;
		pTemp ->m_pNext = reverseNode;
		reverseNode = pTemp;
	}
	return reverseNode;
}

// 3. 查找单链表中的倒数第K个结点 (k > 0)

ListNode * FindKthNode(ListNode *pHead , size_t k){
	//size_t len = GetListLength(pHead);
	if( pNode == NULL || k == 0 )
		return NULL;
	ListNode *pAhead = pHead;
	ListNode *pBehind = pHead;
	while( k > 1 && pAhead != NULL ){
		pAhead = pAhead->m_pNext;
		k--;
	}
	if( k > 1 || pAhead == NULL)  //结点数量小于k，退出。比求node的长度好多了
		return NULL;
	while(pAhead -> m_pNext != NULL){
		pAhead = pAhead -> m_pNext;
		pBehind = pBehind -> m_pNext;
	}
	return pBehind;
}

// 4. 查找链表的中间节点
// 两个指针，一个走1步，一个走2步
ListNode *FindMidNode(ListNode *pHead){
	if( pHead == NULL || pHead -> m_pNext == NULL)
		return pHead;
	ListNode *pAhead = pHead;
	ListNode *pBehind = pHead;
	while( pAhead-> m_pNext != NULL ){
		pAhead = pAhead->m_pNext;
		pBehind = pBehind ->m_pNext;
		if(pAehind -> m_pNext != NULL)
			pAehind = pAehind->m_pNext;
	}
	return pBehind;
}

// 5. 从尾到头打印链表

void PrintListReversingly(ListNode *pHead){
	if( pHead == NULL )
		return;
	else{
		PrintListReversingly(pHead->m_pNext);
		printf("%d\n", pHead->m_nKey);
	}
}

void PrintListReversingly(ListNode *pHead){
	if( pHead == NULL )
		return;
	stack<ListNode*> s;
	ListNode *pNode = pHead;
	while(pNode != NULL){
		s.push(pNode);
		pNode = pNode -> m_pNext;
	}
	while(!s.empty()){
		temp = s.top();
		printf("%d\n",temp->m_nKey);
		s.pop();
	}
}

//6. 已知两个单链表pHead1 和pHead2 各自有序，把它们合并成一个链表依然有序
ListNode *MergeSortedList(ListNode *l1,ListNode *l2){
	if(l1 == NULL)
		return l1;
	if(l2 == NULL)
		return l2;
	ListNode *pNode = NULL;
	if(l1->m_nKey > l2->m_nKey){
		pNode = l2;
		pNode -> m_pNext = MergeSortedList(l1,l2->m_pNext);
	}
	else{
		pNode = l1;
		pNode->m_pNext = MergeSortedList(l1->m_pNext,l2);
	}
	return pNode;
}

//7. 判断一个单链表中是否有环
bool isCircleList(ListNode *pHead){
	ListNode *pFast = pHead;
	ListNode *pSlow = pHead;
	while( pFast!= NULL && pFast->m_pNext != NULL){
		pFast = pFast->m_pNext->m_pNext;
		pSlow = pSlow->m_pNext;
		if(pFast == pSlow)
			return true;
	}
	return false;
}

//8. 判断两个单链表是否相交 （相交的话后半段是相同的）
bool isIntersected(ListNode *l1, ListNode *l2){
	if(l1 == NULL || l1 == NULL)
		return false;
	ListNode *temp1 = l1;
	while(temp1 -> m_pNext != NULL)
		temp1 = temp1->m_pNext;
	ListNode *temp2 = l2;
	while(temp2 -> m_pNext != NULL)
		temp2 = temp2->m_pNext;
	return temp1 == temp2;
}

//9. 求两个单链表相交的第一个节点
ListNode *GetFirstCommonNode(ListNode *l1, ListNode *l2){
	if(l1 == NULL || l2 == NULL)
		return NULL;
	int len1 = 1;
	ListNode *pNode1 = l1;
	while(pNode1 -> m_pNext != NULL){
		pNode1 = pNode1 -> m_pNext;
		len1 ++;
	}
	int len2 = 1;
	ListNode *pNode2 = l2;
	while(pNode2 -> m_pNext != NULL){
		pNode2 = pNode2 -> m_pNext;
		len2 ++;
	}
	if(pNode1 != pNode2)
		return NULL;

	ListNode *pNode11 = l1;
	ListNode *pNode22 = l2;
	if(len1 > len2){
		int k = len1 - len2;
		while(k--)
			pNode11 = pNode11 -> m_pNext;
	}
	else{
		int k = len2 - len1;
		while(k--)
			pNode22 = pNode22 -> m_pNext;
	}
	while(pNode11 != pNode22){
		pNode11 = pNode11 -> m_pNext;
		pNode22 = pNode22 -> m_pNext;
	}
	return pNode11;
}

//10. 已知一个单链表中存在环，求进入环中的第一个节点
ListNode *GetFirstNodeInCircle(ListNode *pHead){
	if (pHead == NULL || pHead -> m_pNext == NULL)
		return NULL;
	ListNode *pFast = pHead;
	ListNode *pSlow = pHead;
	while(pFast != NULL && pFast-> m_pNext != NULL){
		pFast = pFast -> m_pNext -> m_pNext;
		pSlow = pSlow -> m_pNext;
		if(pFast == pSlow)
			break;
	}
	//若不相交，直接退出
	if( pFast == NULL || pFast -> m_pNext == NULL )
		return NULL;
	ListNode *end = pSlow;
	ListNode *pHead1 = pHead;
	ListNode *pHead2 = end -> m_pNext;
	int len1 = 1;
	ListNode *pNode1 = pHead1;
	while(pNode1 != end){
		pNode1 = pNode1 ->m_pNext;
		len++;
	}
	int len2 = 1;
	ListNode *pNode2 = pHead2;
	while(pNode2 != end){
		pNode2 = pNode2 ->m_pNext;
		len++;
	}

	ListNode *pNode11 = pHead1;
	ListNode *pNode11 = pHead1;
	if(len1 > len2){
		int k = len1 - len2;
		while(k--)
			pNode11 = pNode11 ->m_pNext;
	}
	else{
		int k = len2 - len1;
		while(k--)
			pNode22 = pNode22 ->m_pNext;
	}
	while(pNode11 != pNode22){
		pNode11 = pNode11 ->m_pNext;
		pNode22 = pNode22 -> m_pNext;
	}
	return pNode11;
}

//11. 给出一单链表头指针pHead和一节点指针pToBeDeleted，O(1)时间复杂度删除节点pToBeDeleted
void Delete(ListNode * pHead, ListNode * pToBeDeleted){
	if(pToBeDeleted == NULL)
		return NULL;
	if(pToBeDeleted -> m_pNext != NULL ){
		ListNode *temp = pToBeDeleted;
		pToBeDeleted->m_nKey = pToBeDeleted -> m_pNext ->m_nKey;
		pToBeDeleted->m_pNext = pToBeDeleted ->m_pNext->m_pNext;
		delete temp;
	}
	else{ //要删除节点为尾结点情况
		if(pHead == pToBeDeleted){
		 	pHead == NULL;
			delete pToBeDeleted;
		}
		ListNode *pNode = pHead;
		while(pNode -> m_pNext !=  pToBeDeleted)
			pNode = pNode->m_pNext;  
		pNode ->m_pNext = NULL;
		delete pToBeDeleted;
	}
}