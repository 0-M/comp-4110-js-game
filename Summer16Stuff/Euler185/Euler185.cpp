# include <iostream>
# include <utility>



int main(int argc, char* argv[]) {


return 0;
}
















//int comp_digits(int a, int b) {
//    int count = 0;
//    for(int i = 0; i < 5; i++) {
//        if(a % 10 == b % 10) {
//            count++;
//        }
//        a = a / 10;
//        b = b / 10;
//    }
//    return count;
//}
//
//int main(int argc, char* argv[]) {
//    int num_correct = 0;
//    bool found = false;
//    int answer = 0;
//    std::pair<int, int> * pairArr;
//    pairArr = new std::pair<int, int> [6];
//    pairArr[0].first = 90342;
//    pairArr[0].second = 2;
//    pairArr[1].first = 70794;
//    pairArr[1].second = 0;
//    pairArr[2].first = 39458;
//    pairArr[2].second = 2;
//    pairArr[3].first = 34109;
//    pairArr[3].second = 1;
//    pairArr[4].first = 51545;
//    pairArr[4].second = 2;
//    pairArr[5].first = 12531;
//    pairArr[5].second = 1;
//
//    for(int i = 0;found == false; i++) {
//        num_correct = 0;
//        for(int j = 0; j < 6; j++) {
//            int temp = comp_digits(i, pairArr[j].first);
//            if (temp == pairArr[j].second) {
//                num_correct = num_correct + 1;
//            }
//        }
//        if(num_correct == 6) {
//            found = true;
//            answer = i;
//        }
//    }
//
//    std::cout << answer;
//    return 0;
//}



//int comp_digits(long long a, long long b) {
//    int count = 0;
//    for(int i = 0; i < 16; i++) {
//        if(a % 10 == b % 10) {
//            count++;
//        }
//        a = a / 10;
//        b = b / 10;
//    }
//    return count;
//}
//
//int main(int argc, char* argv[]) {
//    int num_correct = 0;
//    bool found = false;
//    long long answer = 0;
//    std::pair<long long, int> * pairArr;
//    pairArr = new std::pair<long long, int> [22];
//    pairArr[0].first = 5616185650518293;
//    pairArr[0].second = 2;
//    pairArr[1].first = 3847439647293047;
//    pairArr[1].second = 1;
//    pairArr[2].first = 5855462940810587;
//    pairArr[2].second = 3;
//    pairArr[3].first = 9742855507068353;
//    pairArr[3].second = 3;
//    pairArr[4].first = 4296849643607543;
//    pairArr[4].second = 3;
//    pairArr[5].first = 3174248439465858;
//    pairArr[5].second = 1;
//    pairArr[6].first = 4513559094146117;
//    pairArr[6].second = 2;
//    pairArr[7].first = 7890971548908067;
//    pairArr[7].second = 3;
//    pairArr[8].first = 8157356344118483;
//    pairArr[8].second = 1;
//    pairArr[9].first = 2615250744386899;
//    pairArr[9].second = 2;
//    pairArr[10].first = 8690095851526254;
//    pairArr[10].second = 3;
//    pairArr[11].first = 6375711915077050;
//    pairArr[11].second = 1;
//    pairArr[12].first = 6913859173121360;
//    pairArr[12].second = 1;
//    pairArr[13].first = 6442889055042768;
//    pairArr[13].second = 2;
//    pairArr[14].first = 2321386104303845;
//    pairArr[14].second = 0;
//    pairArr[15].first = 2326509471271448;
//    pairArr[15].second = 2;
//    pairArr[16].first = 5251583379644322;
//    pairArr[16].second = 2;
//    pairArr[17].first = 1748270476758276;
//    pairArr[17].second = 3;
//    pairArr[18].first = 4895722652190306;
//    pairArr[18].second = 1;
//    pairArr[19].first = 3041631117224635;
//    pairArr[19].second = 3;
//    pairArr[20].first = 1841236454324589;
//    pairArr[20].second = 3;
//    pairArr[21].first = 2659862637316867;
//    pairArr[21].second = 2;
//
//    std::cout << "Calculating: " << std::endl;
//    for(long long i = 1000000000000000; found == false; i++) {
//        if(i % 1 == 5) {
//            i = i + 1;
//        }
//        if(i % 10 == 4) {
//            i = i + 10;
//        }
//        if(i % 100 == 8) {
//            i = i + 100;
//        }
//        if(i % 1000 == 3) {
//            i = i + 1000;
//        }
//        if(i % 10000 == 0) {
//            i = i + 10000;
//        }
//        if(i % 100000 == 3) {
//            i = i + 100000;
//        }
//        if(i % 1000000 == 4) {
//            i = i + 1000000;
//        }
//        if(i % 10000000 == 0) {
//            i = i + 10000000;
//        }
//        if(i % 100000000 == 1) {
//            i = i + 100000000;
//        }
//        if(i % 1000000000 == 6) {
//            i = i + 1000000000;
//        }
//        if(i % 10000000000 == 8) {
//            i = i + 10000000000;
//        }
//        if(i % 100000000000 == 3) {
//            i = i + 100000000000;
//        }
//        if(i % 1000000000000 == 1) {
//            i = i + 1000000000000;
//        }
//        if(i % 10000000000000 == 2) {
//            i = i + 10000000000000;
//        }
//        if(i % 100000000000000 == 3) {
//            i = i + 100000000000000;
//        }
//        if(i % 1000000000000000 == 2) {
//            i = i + 1000000000000000;
//        }
//
//        num_correct = 0;
//        std::cout << i << std::endl;
//        for(int j = 0; j < 22; j++) {
//            int temp = comp_digits(i, pairArr[j].first);
//            if (temp == pairArr[j].second) {
//                num_correct = num_correct + 1;
//            }
//        }
//        if(num_correct == 22) {
//            found = true;
//            answer = i;
//        }
//    }
//    std::cout << answer << std::endl;
//    //std::cout << 2321386104303845 % 10;
//    return 0;
//}

