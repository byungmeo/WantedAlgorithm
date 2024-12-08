#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Node {
    Node* parent = nullptr;
    vector<Node*> childs;

public:
    // 부모 노드를 설정하고 부모 노드에게 자신을 자식으로 추가해달라고 한다.
    void Init(Node* parent) {
        this->parent = parent;
        if(parent != nullptr) parent->AddChildNode(this);
    }

    // 자식 노드를 추가한다.
    void AddChildNode(Node* node) {
        childs.push_back(node);
    }

    // 특정 자식 노드를 벡터에서 삭제한다.
    void RemoveChildNode(Node* target) {
        childs.erase(remove(childs.begin(), childs.end(), target), childs.end());
    }

    // 이 노드를 삭제한다
    void RemoveThisNode() {
        // 자식 노드들을 먼저 삭제한다.
        for(Node* child : childs) {
            child->RemoveThisNode();
        }
        // 벡터를 초기화 한다.
        childs.clear();
        // 부모에게 자신을 삭제해달라고 한다.
        if(parent != nullptr) parent->RemoveChildNode(this);
    }

    // LeafNode의 갯수를 구한다
    int GetLeafNodeCount() {
        // 자식 노드가 없을 경우 자기 자신이 LeafNode이기 때문에 1 반환
        if(childs.size() == 0) return 1;

        // 자식 노드가 있을 경우
        int cnt = 0;
        for(Node* child : childs) {
            cnt += child->GetLeafNodeCount();
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int r; // root 노드의 번호를 저장
    Node* root;

    int N;
    cin >> N;
    vector<Node> nodes(N); // nodes[i] -> i번 노드를 바로 가져온다
    for(int i = 0; i < N; i++) {
        int p;
        cin >> p;
        if(p == -1) {
            r = i;
            root = &nodes[i];
        }
        nodes[i].Init(p == -1 ? nullptr : &nodes[p]);
    }

    int d;
    cin >> d;
    // 리프 노드의 개수를 출력한다.
    if(d == r) cout << 0; // 루트 노드일 경우 그냥 0
    else {
        nodes[d].RemoveThisNode(); // 노드를 삭제한다.
        cout << root->GetLeafNodeCount();
    }
}
