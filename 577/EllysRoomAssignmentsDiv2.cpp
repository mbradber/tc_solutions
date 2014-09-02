#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;

class EllysRoomAssignmentsDiv2 {
    public:
    double getProbability(vector<string> ratings) {
        string allRatings = "";
        vector<int> vRatings;
        
        for(int i = 0; i < ratings.size(); ++i){
            allRatings += ratings[i];
        }
        
        string delim = " ";
        int pos = 0;
        
        while((pos = allRatings.find(delim)) != string::npos){
            string token = allRatings.substr(0, pos);
            allRatings.erase(0, pos + delim.size());
            vRatings.push_back(atoi(token.c_str()));
        }
        
        if(allRatings.size() > 0){
            vRatings.push_back(atoi(allRatings.c_str()));
        }
        
        int ellyScore = vRatings[0];
        int ellyRank = 1;
        int numRooms = vRatings.size() / 20;
        if(vRatings.size() % 20 != 0){
            numRooms++;
        }
        
        if(numRooms == 1) return 1.0;
        
        for(int i = 0; i < vRatings.size(); ++i){
            if(vRatings[i] > ellyScore){
                ellyRank++;
            }
        }
        
        if(ellyRank == 1) return 1.0;
        
        if(ellyRank <= numRooms){
            return 0;
        }
        
        return (double)((double)1 / (double)numRooms);
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool double_equal (const double &expected, const double &received) { return abs(expected - received) < 1e-9 || abs(received) > abs(expected) * (1.0 - 1e-9) && abs(received) < abs(expected) * (1.0 + 1e-9); }

bool do_test(vector<string> ratings, double __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    EllysRoomAssignmentsDiv2 *instance = new EllysRoomAssignmentsDiv2();
    double __result = instance->getProbability(ratings);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << pretty_print(__expected) << endl;
        cout << "           Received: " << pretty_print(__result) << endl;
        return false;
    }
}

bool run_testcase(int __no) {
    switch (__no) {
        case 0: {
            string ratings[] = {
                "724 42 13 17 1199 577 1001 1101 483 845 196 1163 3",
                "60 985 296 1044 917 1007 898 119 1016 23 56 1159 1",
                "194 372 951 991 947 1053 433 1017 1011 391 110 9 2",
                "30 245 788 830 747 2 3"
            };
            double __expected = 0.3333333333333333;
            return do_test(to_vector(ratings), __expected, __no);
        }
        case 1: {
            string ratings[] = {
                "42 911 666 17 13 1 1155 1094 815 5 1000 540"
            };
            double __expected = 1.0;
            return do_test(to_vector(ratings), __expected, __no);
        }
        case 2: {
            string ratings[] = {
                "1168 196 440 643 227 1194 1149 372 878 23 767 296 ",
                "110 52 840 367 790 884 620 676 380 1007 304 262 10",
                "63 917 230 951 635 898 894 319 724 597 470 1143 62",
                "7 1175 436 484 457 991 433 747 8 94 830 1044 1053 ",
                "360 1167 391 364 1120 192 56 528 366 712 480 83 11",
                "59 483 949 356 1163 9 845 750 781 784 1016 985 346",
                " 466 947 73 911 690 630 609 866 788 98 1017 410 11",
                "9 617 245 801 205"
            };
            double __expected = 0.0;
            return do_test(to_vector(ratings), __expected, __no);
        }
        case 3: {
            string ratings[] = {
                "470 840 410 1168 637 464 498 1118 276 1013 989 874",
                " 64 192 296 611 44 999 583 365 1195 20 838 274 425",
                " 236 960 1116 857 630 664 98 1046 807 1111 529 47 ",
                "31 676 1112 42 376 56 1105 814 6 871 364 319 1145 ",
                "491 199 1121 713 353 956 579 445 1031 627 618 202 ",
                "763 271 188 1140 1044 311 895 1175 74 465 454 708 ",
                "1181 866 387 99 784 700 308 853 977 253 62 782 371",
                " 8 908 1151 83 932 55 1077 897 517 767 990 567 869",
                " 607 603 499 356 772 310 332 357 845 1159 1128 104",
                "2 783 953 315 1020 360 696 793 847 1 716 731 1097 ",
                "660 302 761 484 23 89 609 161 978 312 87 363 879 6",
                "02 635 409 749 475 106 632 961 1053 414 422 1146 6",
                "51 970 907 719 110 118 218 471 334 747 645 575 757",
                " 156 137 101 150 1084 48 859 1016 396 779 791 195 ",
                "1148 138 141 304 523 1129 940 569 1058 113 949 967",
                " 261 1017 433 126 205 679 998 325 831 239 774 245 ",
                "992 407 991 667 489 580 628 1055 383 924 706 369 8",
                "37 380 596 392 734 183 397 1165 911 657 1028 617 1",
                "45 105 870 707 447 281 841 526 367 297 66 851 643 ",
                "1142 168 480 3 347 1101 737 1025 647 588 1049 458 ",
                "508 759 654 927 744 937 402 440 1158 620 1067 528 ",
                "1001 1186 705 124 511 597 395 1063 399 753 1093 10",
                "05 717 1173 278 81 762 71 51 801 890 1185 413 674 ",
                "252 805 775 52 612 1075 1187 131 559 72 1141 298 8",
                "5 640 1184 290 1127 423 925 1108 114 864 605 802 1",
                "39 962 104 817 289 816 359 323 1068 368 477 1022 2",
                " 377 512 688 1029 340 28 1193 910 417 984 1163 385",
                " 858 212 119 898 9 473 180 140 346 262 971 170 564",
                " 226 123 698 196 10 466 1174 446 248 1194 227 94 3",
                "09 850 1179 1035 680 750 67 650 765 61 982 412 736",
                " 149 822 933 621 117 1062 678 929 693 125 836 852 ",
                "694 711 275 358 524 825 997 372 781 873 725 818 57",
                "1 1041 460 796 287 723 142 322 691 220 830 778 116",
                "7 68 1059 1011 958 324 200 947 29 216 57 443 488 9",
                "85 666 690 1182 230 1114 153 73 1086 191 1010 586 ",
                "250 96 211 40 217 1155 82 641 1066 1131 896 154 22",
                "4 5 951 917 1189 709 777 1034 724 436 626 270 1052",
                " 593 50 926 901 634 1082 943 894 721 945 366 391 4",
                "27 646 1076 712 496 868 435 1120 177 1149 330 483 ",
                "1152 351 176 457 1126 235 1143 790 780 1166 686 80",
                " 121 222 305 355 581 476 34 533 147 316 881 539 45",
                " 146 263 22 788 527 519 1069 710 59 148 234 661 81",
                "3 1081 133 884 548 405 344 451 887 789 1007 295 39",
                "8 728 553 642 878 77 293 684 877 554 478"
            };
            double __expected = 0.037037037037037035;
            return do_test(to_vector(ratings), __expected, __no);
        }

        // Your custom testcase goes here
        case 4: {
            string ratings[] = {"1197 182 958 625 624 370 1178 952 823 340 663 686 ", "1189 244 503 790 814 451 656 551 452 740 188 996 3", "33 1132 1053 935 687 326 612 969 1034 832 263 816 ", "925 682 571 541 725 165 597 729 207 224 161 619 47", "8 237 598 1119 766 605 874 228 264 432 246 674 21 ", "751 202 931 174 311 951 444 702 770 971 1141 1091 ", "860 19 168 418 997 700 634 689 283 882 817 521 100", "6 26 977 399 601 258 230 235 477 567 23 1021 557 3", "4 319 328 77 810 1142 37 295 1045 209 1058 390 4 2", "51 39 408 726 805 63 9 104 778 758 583 532 17 420 ", "1171 179 978 442 1195 1183 111 851 980 668 513 110", "4 73 459 466 856 303 45 1122 474 694 752 909 1145 ", "948 514 29 1159 515 27 360 910 627 1179 272 482 59", "1 445 638 50 108 924 695 191 256 1191 448 262 609 ", "1165 248 718 715 1148 382 327 424 872 569 904 94 5", "28 743 1030 206 995 840 387 572 267 456 539 231 13", "8 529 819 650 1153 310 43 1188 281 329 473 942 429", " 494 547 1074 426 1061 821 479 696 999 748 699 116", "4 1033 449 658 1000 292 226 64 803 491 864 815 708", " 223 158 1180 1196 197 7 1131 375 1060 545 180 993", " 781 30 984 1031 371 1073 861 834 1092 476 818 112", " 185 692 240 745 930 828 350"};
            
            double __expected = 1.0;
            return do_test(to_vector(ratings), __expected, __no);
        }
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "EllysRoomAssignmentsDiv2 (500 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 5; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1409539219;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
