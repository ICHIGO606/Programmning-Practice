class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int>result;
    	
    	queue<Node*>q;
    	q.push(root);
    	int count=0;
    	while(!q.empty()){
    	    int size=q.size();
    	    
    	    count++;
    	    for(int i=0;i<size;i++){
    	        Node* temp=q.front();
    	        result.push_back(temp->data);
    	        if(count%2!=0){
    	            
    	            if(temp->right)q.push(temp->right);
    	            if(temp->left)q.push(temp->left);
    	        }
    	        else{
    	            if(temp->left)q.push(temp->left);
    	            if(temp->right)q.push(temp->right);
    	        }
    	        q.pop();
    	    }
    	    
    	}
    	return result;
    }
};