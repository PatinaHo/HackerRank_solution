/* Subdomain: Trees
 * Problem: QHEAP1
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct minHeap{
    int n;  //number of nodes in heapArr
    int heapArr[100000];
    minHeap(){n = 0;}
    void insert(int item);
    void del(int item);
    int search(int item);
    void min_heapify(int index);
    int getMin();
};

void minHeap::insert(int item){
    n++;
    heapArr[n] = item;
    int cur = n; //current index when doing bottom-up checking
    int p = cur/2; //p: cur's parent
    while(cur > 1){
        int p = cur/2;
        if(heapArr[p] > heapArr[cur]){
            swap(heapArr[p], heapArr[cur]);
            cur = p;
        }
        else break;
    }
}

void minHeap::del(int item){
    int index = search(item);
    if (index != -1){
        heapArr[index] = heapArr[n];
        n--;
        min_heapify(index);
    }
}

int minHeap::search(int item){
    for (int i = 1; i <= n; i++){
        if (heapArr[i] == item)
            return i;
    }
    return -1;
}

void minHeap::min_heapify(int index){ //由上而下調整以index為root的樹成為heap
    int min = index;
    int l = 2*index, r = 2*index + 1;
    if(r<=n && heapArr[r] < heapArr[min]){
        min = r;
    }
    if(l<=n && heapArr[l] < heapArr[min]){
        min = l;
    }
    if(min != index){
        swap(heapArr[index], heapArr[min]);
        min_heapify(min);
    }   
}

int minHeap::getMin(){
    return heapArr[1];
}

int main() {
        
    minHeap h;
    int query_num, query_type, item;
    cin >> query_num;
    
    for (int i = 1; i <= query_num; i++){
        cin >> query_type;
        if(query_type == 1){
            cin >> item;
            h.insert(item);
        }
        else if(query_type == 2){
            cin >> item;
            h.del(item);
        }
        else if(query_type == 3)
            cout << h.getMin() << endl;
    }
    
    return 0;
}