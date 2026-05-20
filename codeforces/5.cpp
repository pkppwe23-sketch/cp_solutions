#include <bits/stdc++.h>
using namespace std;

// formation of binary tree using recursion

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

node *buildtree(node *root)
{

    cout << "enter the data" << endl;

    int data;
    cin >> data;

    // base condition
    if (data == -1)
    {
        return nullptr;
    }

    root = new node(data);

    cout << "enter value in the left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "enter value in the right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraverse(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            // one level is completely traversed
            // go to another node
            if (!q.empty())
            { // queuestill has some childnode;
                q.push(nullptr);
            }
        }

        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// INORDER == LNR

void inorder(node *&root)
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    
}

// PREORDER == NLR

void preorder(node *&root)
{
    // base case
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);

    preorder(root->right);
}

// postorder==LRN

void postorder(node *&root)
{
    // base case1
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);

    postorder(root->right);
    cout << root->data << " ";
}

//level order formation of tree  earlier that is recursion way

Node* buildfromlevelorder(node* root){

    queue<node*>q;
    cout<<"enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"enter left node for "<<root->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        if(rigthdata!=-1){
            temp->right=new node(rightdata);
            q.pudh(temp->right);
        }

    }
}

int main()
{

    node *root = nullptr;

    // creating tree
    root = buildtree(root);
    levelordertraverse(root);
    inorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    postorder(root);
    cout<<endl;

    return 0;
}
