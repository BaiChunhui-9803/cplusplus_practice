
#include <iostream>
#include <vector>

using namespace std;
#define MAX_SIZE 1000

struct node
{
    int key;
    int l, r;
};

node tree[MAX_SIZE] = { {0, 1, 0} };
int cnt;

inline void trans(vector<string>& x, string before, string after)
{
    for (auto& p : x)
        if (p == before)
        {
            p = after;
            break;
        }
}

void show(int root, vector<string> pre = vector<string>(0))
{
    auto& p = tree[root];

    if (p.key != 0)
    {
        vector<string> temp(pre);
        trans(temp, "©°©¤©¤", "   ");
        trans(temp, "©¸©¤©¤", "©¦  ");
        temp.push_back("©°©¤©¤");
        show(p.l, temp);
    }

    for (auto& i : pre)
        cout << i;
    if (p.key == 0)
        cout << "null" << endl;
    else
        cout << p.key << endl;

    if (p.key != 0)
    {
        vector<string> temp(pre);
        trans(temp, "©°©¤©¤", "©¦  ");
        trans(temp, "©¸©¤©¤", "   ");
        temp.push_back("©¸©¤©¤");
        show(p.r, temp);
    }
}

void add(int key, int& root = tree[0].l)
{
    if (root == 0)
    {
        root = ++cnt;
        tree[cnt] = { key };
    }
    else if (key < tree[root].key)
        add(key, tree[root].l);
    else
        add(key, tree[root].r);
}

int main()
{
    for (int i = 1; i <= 10; ++i)
        add(rand() % 100);
    show(1);
}
