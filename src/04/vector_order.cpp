
#include <iostream>
#include <vector>
using namespace std;


int main(){
    std::vector<int> std_vector;

    int itr_num = 1000000;
    int copy_area = 0; // 確保したメモリの累積和

    for(int i = 0; i < itr_num; i++){
        // 足りなくなったから別の場所にコピーする判定
        if(std_vector.capacity() == std_vector.size()){
            // cout << i << ":" << std_vector.capacity() << std::endl;
            if(std_vector.capacity() == 0){
                copy_area += 1;
            }else{
                copy_area += std_vector.capacity()*2;
            }
        }
        std_vector.push_back(1);
    }

    cout << "push_back回数 " << itr_num << endl;
    cout << "使用メモリ量 " << copy_area << endl;
    cout << "使用メモリ量平均 " << 1.0 * copy_area / itr_num << endl;
    
    return 0;
}
