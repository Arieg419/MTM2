Node recursiveFunc (Node head, int n, int* nodeCounter) {
		Node nodeToReturn;
	    if(head->next == NULL) {
	       return NULL;
	    }
	    nodeToReturn = recursiveFunc(head->next, n, nodeCounter);
	    *(nodeCounter) += 1;
	    if(*nodeCounter == n) {
	        return head;
	    }
	    return nodeToReturn;
}

int* xthToLast(Node head, int n) {
	if(head == NULL) return NULL;
	if(n < 0) {
		return NULL;
	}
	int nodeCounter = 0;
	Node ptr = recursiveFunc(head, n, &nodeCounter);
	return &ptr->data;
}