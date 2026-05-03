#include<iostream>
#include<unordered_set>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 //合并有序链表
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode* p = list3;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                p->next = list1;
                list1 = list1->next;
            }
            else {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if (list1 == nullptr) {
            p->next = list2;
        }
        else if (list2 == nullptr) {
            p->next = list1;
        }
        return list3->next;
    }
};

//删除链表的中间节点
class Solution2 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* temp = p1;//最后指向中间节点的前一个节点
        //处理特殊情况
        if (head == nullptr) {
            return nullptr;
        }
        else if (head->next == nullptr) {
            return nullptr;
        }

        while (p2 != nullptr && p2->next != nullptr) {
            temp = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        //删除
        temp->next = temp->next->next;
        delete(p1);
        return head;
    }
};

 
//重排链表
class Solution3 {
public:
    void reorderList(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        //处理特殊情况
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return;
        }
        while (p2 != nullptr && p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* reverseNode = reverse(p1->next);
        p1->next = nullptr;
        //插入
        ListNode* p3 = head;
        ListNode* p4 = reverseNode;
        while (p4 != nullptr) {
            ListNode* temp1 = p3;
            ListNode* temp2 = p4;
            p4 = p4->next;
            p3 = p3->next;
            //将temp插入到第一个链表中
            temp2->next = p3;
            temp1->next = temp2;

        }
    }
    ListNode* reverse(ListNode* newHead) {
        ListNode* prev = nullptr;
        ListNode* cur = newHead;
        while (cur != nullptr) {
            ListNode* nextTemp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nextTemp;
        }
        return prev;
    }
};


//环形链表
//哈希表法
class Solution4_1 {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*>visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};
//快慢指针
class Solution4_2 {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (true) {
            if (fast ==nullptr||slow==nullptr||fast->next==nullptr||fast->next->next==nullptr||slow->next==nullptr) {
                return false;
            }
            else if (fast ==slow) {
                return true;
            }
            else {
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        return false;
    }
};
int main() {
    return 0;
}