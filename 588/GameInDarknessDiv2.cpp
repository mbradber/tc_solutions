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

int dp[50][50][50*50];
int M;
vector<string> F;

int op(int r, int c, int m){
    if(r >= F.size() || r < 0 || c >= F[0].size() || c < 0 || F[r][c] == '#'){
        return 0;
    }
    
    if(dp[r][c][m+1] == 0){
        return 0;
    }
    
    int& res = dp[r][c][m];
    if(res == 0) return 0;
    
    if(m == M){
        return 1;
    }
    
    if(res == -1){
        int a[4];
        a[0] = op(r + 1, c, m + 1);
        a[1] = op(r - 1, c, m + 1);
        a[2] = op(r, c + 1, m + 1);
        a[3] = op(r, c - 1, m + 1);
        
        res = *max_element(a, a + 4);
    }
    
    return res;
}

class GameInDarknessDiv2 {
    public:
    string check(vector<string> field, vector<string> moves) {
        memset(dp, -1, sizeof(dp));
        
        string builder = "";
        for(int i = 0; i < moves.size(); ++i){
            builder += moves[i];
        }
        
        M = builder.size();
        F = field;
        
        pair<int, int> aStart, bStart;
        for(int i = 0; i < field.size(); ++i){
            for(int j = 0; j < field[0].size(); ++j){
                if(field[i][j] == 'A'){
                    aStart = make_pair(i, j);
                }
                else if(field[i][j] == 'B'){
                    bStart = make_pair(i, j);
                }
                else if(field[i][j] == '#'){
                    for(int k = 0; k < M + 1; ++k){
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
        
        for(int i = 0; i < builder.size(); ++i){
            dp[aStart.first][aStart.second][i] = 0;
            
            if(builder[i] == 'R'){
                aStart.second += 1;
            }
            else if(builder[i] == 'L'){
                aStart.second -= 1;
            }
            else if(builder[i] == 'U'){
                aStart.first -= 1;
            }
            else if(builder[i] == 'D'){
                aStart.first += 1;
            }
            
            if(i == builder.size() - 1){
                dp[aStart.first][aStart.second][i + 1] = 0;
            }
        }
        
        int res = op(bStart.first, bStart.second, 0);
        return res > 0 ? "Bob wins" : "Alice wins";
    }
};

// CUT begin
// Array to vector converter
template <typename T> vector<T> vector_wrapper(T arr[], int n) { return vector<T>(arr, arr + n); }
#define to_vector(arr) vector_wrapper(arr, sizeof(arr) / sizeof(arr[0]))

template <typename T> string pretty_print(T t) { stringstream s; typeid(T) == typeid(string) ? s << "\"" << t << "\"" : s << t; return s.str(); }

bool do_test(vector<string> field, vector<string> moves, string __expected, int caseNo) {
    cout << "  Testcase #" << caseNo << " ... ";

    time_t startClock = clock();
    GameInDarknessDiv2 *instance = new GameInDarknessDiv2();
    string __result = instance->check(field, moves);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
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
            string field[] = {"...#......#..##.#........#..#...#...#..#..##......", "#.##.#..#..##.....#.#.....#..#....#..##..#..#...#.", ".#..#...#...#..##......#.......#.#.....##.##...#.#", ".##.#.#..##......#.####...#..#.#..#.#...#.#.....#.", "..#..##....#.#.##.#...#.#..##.#..#...........#....", ".#.#.#..#...#....#...#....#......#.#.#.#...##.#...", "#..#.....#...#.##.........#......#.....#.#####....", ".##...#.##..#....#..#.##.#...#..#.#........##..##.", "...#..#.......##....#..#..#...#.##..##.......#...#", "#..#.#.#.............#.##....#.....#.........#....", "...........#.....##......##..##..#..#.#..#.##.....", "#.#....##..##..#..#.#...........#..#..##.#.##.#.#.", ".#.#....#.#.#...##.#......#..##..#..##..###.....#.", "..##...#....#.##.....##.....#...#..#.#.#.#.....#.#", "....#..#.#.#...#..........#...##.##...#.#..##.##..", "..##.##...#.#.#..#....#...#...#..#.#...#...##.#.#.", "#.......##...#.....##..##.#..#.#....#.#.#.#...#.#.", "...#..#...#######.#..#...#.##..##...##.#...#..#.##", "....#..#.#...#.......##.#...#.....#..#...#.....#..", "#.####.#.###..#....##..#....#..#.#..##...#.#.#.##.", "..#.#.#....#......#..#...###.#........###.#...#.#.", ".....#..##..#..###..#..#....##...#......##.###...#", "..#...#.....#......#..#..#..#.##.#.#.#.#..#.......", "#.##.#.#.#.#.#.##.#.....#..#.#.#......#..#......##", ".#..####..##....#..#..#..###..#.#......#.#.#..#...", "...#.#..#...#...#.#...#.#...##.......##.#....#..#.", "..#....#..#......#.....#..###.#..#.#......##.....#", "#..#.##..##..#..#.#...#...#...#...#...........##..", "..#.#...#...#.##......#.####........#.#......##.##", ".##..##..##..#..#.#.#.....#......#.#.#.........#..", "##.##.###.....#...#..#......#...#.....##..##...##.", "...#.#........##.#....#..#.#.#.#.###....#.........", "....#.####..#..#.#.###.##.##.........##.#.#.#.#.#.", "...#.##..#.#.....#...#.#...A#.#....#.....#...#...#", "..........#..#.#.##...#.##....#.....#.#..#..##....", "##.....#.#.#...##.#.##.#.......#.........##...#.#.", ".......#.#....#..#.....##..#..#..#..#.##...#..#.#.", ".##..#..###...#...##.##..#..###.....##....#..#..#.", "...#.#.#.#...#..##......#............#..###..##...", "#.#..##...##..#....#.....##...........#.#..##.##.#", "...#....#.#..##.#.#.#..#...#..........#..#.#.#..#.", ".#.##..####.#..#..#..#...##..##...#......#.##.#..#", ".##.#...#..##....#....#.#......##...#.#..#....###.", "..#..#..##.#..#......#.#.##.###.####.........#...#", ".##.......#.##..##..#..##..#..##...#.....##..#..#.", ".#.....#.##..#...#.#..#..###...#.#........#.#...#.", "#.....#..#.#.#...#...#.##...##.###.#.#.....#..#...", "...#...##.#.#...#.#..B...#.#.##.....#.....#....#.#", ".#.....##.##.#.##..##..#.##....#..#....##..##.....", ".#..#....#...#...#......#..#..#.....#.#.#...#....."};
            string moves[] = {"DDRLRRULDLLUDLRLLRLRLRLRDURDUDLRLULRLRDRLULRDRUURR", "DULDULURDLRDRLLLDRULRRRDURRLLDUDRURLDULUDRDUUDLDUR", "UUUDDLDLULRUDRLLRDURDDRLULURDLRULRDURDRLRLULDLULDL", "DUDRDULULRLRLRLRLRRRRDUULRRDDULDUDULRDUDRLRLRLRUUD", "UUDLDLLRLLRDUURDLUDRLRRLLDDRDLRULDRLRUDLLRLRURLRDU", "LRDUDDULRUDLLRURLDLRURLRDLRLURLRDUDRDUDUDLURRLLULD", "RLURDRDLRULULDLRLRUDRDUDUDRULRLRRRRRDLLRRLDLLRUDLR", "LUUDRURRRURLLDRDURLLUDRRDRLRRULUDRDRDULDRLDLUULRUU", "DUDUUUULLDLRUULLURUDDUDULDRULRLRUDRLRRLLDLURRDDLDD", "UURURLDDURLDLRULURRLRLDURLDUURRLDLULLDRRURDLRLURLD", "LUUDDULLRDRRUDLLURDULRRRLDURDULRLLLRUDUDDDLRRLUULR", "LDDRDDDUDLURUULUUDDURUUDUDUDUDUDDLRRULRDRLRDULRLLL", "UDDUDUUDDUURUDLDRUUDDRULRRRLLDRLLLUDUDURRRDULDRLLL", "DRLUDURDUDLRDURDLRRDRLDLRLLULDRUUUDDDLDURDRLLUURUR", "LUURULLRRLLDUDULRDUDDRRRUDULRDLLUDUULLRRLLRRRDUDLR", "LRRLDDRRUDDLDUDDLLLDUUDDRLRDRLRUUDLUDRLRLDLDRRUDDR", "RUUDUDRULURLDRDRRLLUUUDDRUDLURDDUUDLLDRULULUDUDUUU", "DLDULUURUDULDURUDLURDUULRLRLLRLLUDUDRRLDUDRRDDUURL", "DRDUDLURLLDULRULURDDRULUDDLRLRRULURRLRDDRDRLLLRLLR", "URDLUDLRLDLDDRRDULDDUUULRDURLLDURUDUDRDUDLLLRLLLRL", "LDUDULRDRDDURLUDRUDRRULDULDUULDLRDDURRURUDUUDLLRRD", "UUDRUDUDUDLDLUDDRDRRURLRRRULDDULRRUUDRDDRRDRDDUUDL", "RDDRLRDDDRLRLRLRLUUDURLRLRLLDRUDDUULDUDLLLRUUULUUD", "RLUDDULDRRDDDDLDUDURLURUURDLDRUDUUDLDUUDRDULUULLDU", "UDRLURUDDDRURDRDUUUDLLLRULRRURDRLDURLDUULUDRLRUULU", "DUDUULUDRUDDUUDLRDULRULRDUDLRDDDDRULRDUDDLLLUDUUUD", "RLDDUUULDRLUURLDDRLUDUURLDLLLULDUUDDRRURULRUUULUUU", "RRDRDDRLRRLRURLUUDUUDULRDDRDUDLRDDRLDUUUDDDRLRLRUD", "LRURLLUULRLRLRULUDLLLRDULRDURRLLDUDULRDULUUUDRLDDR", "RLDUDDLLULRLLDLRUUDRUURRUDDUURRRLLRRDDLRLLLUDRDDRL", "LLRLRRLRUUDDLLLRRRDULLRLULRLUUDDLLULDUDURDRRUDRLDU", "RDRRUDUURRUULLULRLUDDRUDLRRRLRLLULRDRRDDDUUDDULRLL", "RLLUDUURLUDDLLLRDLRUDLDLLRULUDDUURDDLRULRLRLRUDRUL", "DLDRRDUURUDURRUDURLDUDDUURUDRRLLRLRLLRUDLRULLRDDDU", "LLDUDDULLRDDRLRLLRLRURULDRULURDDUDLLRUDDRDRUULRDUD", "LRDLUUUUDLLUUDUDRRRRDULLLRRRLRLRDUUDLRURULUDRLLRUD", "LLLRRRUDLRUDDDURRRDDLLLUDRRRRDLURLUDDRUDULUULLUDRR", "LLUDLRRLLUUDDUUDLLLRUURURRURLRRRRUDLLDUUDRLRDDDRUD", "RRURDLRUULRRLLDRLDRLURURLURLRLUURULLUDLRURDDUULDLD", "DLDLRDRLUUDDUDRDLUUDDLULLLLUDRRRURDLRLLLLURLDURLUU", "DURUDRLULLLDURRLRRLUURUDRDURLLUDRRLRLLLRULRLDRUDUD", "ULRLDULLDRLULRRDLDUDDLRUUDUDUDUUDUUDLLLRDDUULDLRRL", "URRLUURUULUUDLRDUUDUDDRLUUDUDLRLRDRLRRRDDDUDDDRDDU", "DRDLRRLULLDRLUDRDLRLRUDLLRLUDRRDULRULDRULLDRLULUDR", "RLRRURDRLUDUDLDDDUULLURRLUDURUULUULDDRUDRLLRLULLUU", "LLUUDLDRDDDRULRLDUULRDULURUUDDRRRLDDRRDRURDLUUUUUL", "DUUDLLUDUDRLULRLRDRRDRDRLDUDLDRRLLRUDLDRLULLRRLLLL", "RLDRURRLLRDDDRDDRLUDUDRLUUDURDURRUUDUDDLDLRDRULRDL", "LDURRLUURLRUUDUUDDURLRUDRRLRLLUDLRLLLULRUDLLLDRDUD", "DRDRDLUULUDRLRRDDDUDUUDLLDDRDULRDUDRLRDUDDRRLLLRRR"};
            string __expected = "Bob wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }
        case 1: {
            string field[] = {"...##...", "......#.", "..##B##.", ".#..##..", ".##....#", "#....#.#", "..#.#.#.", "A..#...."};
            string moves[] = {"RRLRLLRRLUURRRUDLUDLRRUDLDULLDDULDRUDUDUDLRRLLUDRR", "LUURRLRURLRLDRUDLURLRDULDUDRLUDRUDLLRLRUDURLUDRDLL", "RLLDDUURLDDLRLURURLRRURDUDURRLLLULRLRLRLRDRRRDUUDD", "UDUURUUULRLRLRLLDURRDDUUDULLRRLRLLRRDULRDDDUUDDLRL", "RLDDUUDDUDUDUUDURLDLRLRDUUDDULLLDRURRDUDULRLRURLRU", "UUDDDUDUUUDDDUDLDDULLRRURLDUDLLDLDULRDULLDURRRLRUD", "LDULRDURLLLDDRLLURDRLLUDURUDDRLULDRRLULDURDLUDRRLL", "RLUDURDLURDRLRLLURUDDUDRLRLLRUDLURURLRRDULLRRDUUDR", "UDUDUDLDUUDRLLRLRLRDUUUDRDLLRDUDUDULRDUDUDURLRURRD", "UUDUDLLRRUDUDUDLRDUUDUDURLRUDUDLRUUDUDUULRDDUUDUDD", "UDUULLDURRDDUDUDDLDLLDLUUDUDDRLRLRULRDLUDLRURDLLRU", "DDUDUDULRDUDUDUUDLRLLDDLURDUUDLRLRLRDLRRLLRRLULDUD", "UDRLRRLLRRLLUDRUUDUDLDRUDUDULDUDURLDRRLRLRLUDLRLRR", "LUDLRRLUURRDUURRLRRURUDUUDUUDDDUDLRLRLDURUUDUDUDDL", "DDUDUUDURUUULRDDUDDUDLDDUURLRUUDDUUDDUDUUUDUDDUDDU", "UULRDDDUDUDLRLRUUULRDDUUDDDUUULLRLDLDUDULRDURLDULR", "LRLRLRRLLLRLLDLUURRLDDUULDDURDLRULDDDUDUURLDUURLRR", "RRRURRDUDUDUDDDLDDULRDUUDUDLRURLRLDUDDUDUDULRDULLL", "RLULRLRLRLRLRDRLDRUDURLLDDUURDLDULLRLDUDDLRUDRLRLR", "LLURURLDURLRRLRUUDULRDRLUDDRLUUDRDLUDRLLRRURRURUDU", "DUDLRUUDDLRLRLRUDLDLLRLLULRDRRLDULULRDRRLDLUDLRLRR", "LDUDUDURURRDUDULRLLRRUDURUDUUULRLRLRDDUULRDUDUDDUD", "DLRLRLRUDUDLRLRLRUUULRLRDUDULRLRLLRRLLRRDUDUDDDLDL", "LRRLRDUDULRUDURLRLDUDDULRUDLRDUDUUDDUDUUDDULRDULRL", "RUDLRURLRUUULRDDUDUDUULLDUDLDUDURLDULLUDULDURDUDUL", "DDLRUDLDUUURDUDLRDLUDRURUDUDULDDLRLRUULRRLRDULLRLR", "RLRDLDUURDUDRRRLRLLRDULLRLUDRLRLUDLDLUDDDUDUUDDUUR", "UDUUDDLDDUUDDUUURLRDULRLRURLLDRDLUDRLRLUDUURLRDRRL", "RRDUDUDULRDURLLLUDLULDDURDLURRRLUDLLRDURLRUDLDURRR", "RURLRLRRDDDUUULRLLRRLRDUDUDDDUUDUUDDDLRUDUDLRLRLDU", "DDUUDLRDUUDLRURLRLRUUUDDDLRLDDUDUDUURLRLRUUULLDLLL", "RRLRLLLURDULLRLRDRRRLRLRRUDUDLRLDURLDULRRUDURLDURL", "RLRLDUDURLRLDLLLUDRLLURLLDRLUDUDRLDRULUDURLDRRLUDL", "UDRLDDDUDUDUDUURLRULRDULUDRDLDUURLRURDRRLLUDUDULRD", "RRRURLDLLLUDULDRLRLDLUURLRRDRLLURDULDLURRLDURDLDUL", "DRLRLDURURRRRLLLLRRRLLULDDLRLURLDDUUDDDUUUURRLLDDD", "DUUURRLDLRUDULDUUDRDLURUDLURLDRDULURDLURRDRLULDURD", "RRDURLRLRUDLDURURLRRLRDUDULRDDUUDULRLRLLDUDURLRRDD", "UDDUUDDUDUUDUDUDDLRLDLLLRLUDULRDULRDULRLRDULRLRDUD", "DLLRRDULLDURRRLUDLRURRLRRLRUDDUUDDUUDDUDUDUUDDULRL", "LLRLDRLRULRRLRLDULRDLDULRDULRURRLLDDUDULRDURURLRLD", "UDURRURUUDUUDUDULLDLRLLRLLRRLLLLUDRRUDLULRLDURLDUD", "UDRLDDDUDUUURULDDRLDDUDUDUURLRLUDRUDUURLDRUDLRULDD", "LRUDLURRULRLRDLULRLRLRLDUDURDLDURUDRRRRUDURLDLRURR", "LLRLRLDLRLRLDULLRLLDUUDLRLURRLLDURRLLRDDULDUUDUDUR", "LDURLRLRLRLDDUUDRLDUDRULURLRRLRLLRRLRDRLLLUDURRLDL", "RRLUDLUDUDUDURLDRLUDRRRLULRDULRLRLLRLDDDDUUDURLUDR", "URULLRRLRDLRUDLRRRDULRDUDUDULRDUDURLLRDULRLRDUDUDU", "LRLRRURLRRLRLLRLRRDDUDUDDLDLLLULRDRRRLRDUURLDURLRU", "DUUDDLRLDDUDULLLRRRDULLDLUDRURLLRDLRLDUUUDUDRDUDLL"
            };
            string __expected = "Bob wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }
        case 2: {
            string field[] = {
                "A.B..", "##.##", "##.##"
            };
            string moves[] = {
                "RRDUR"
            };
            string __expected = "Alice wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }
        case 3: {
            string field[] = {
                "A.###",
                ".B..."
            };
            string moves[] = {
                "RDRRRLLLLUDUDRLURDLUD"
            };
            string __expected = "Bob wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }
        case 4: {
            string field[] = {
                ".....",
                ".#.#.",
                "##.#.",
                "A###.",
                "B...."
            };
            string moves[] = {
                "D"
            };
            string __expected = "Alice wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }
        case 5: {
            string field[] = {
                ".#...#....#.......#....#......",
                "...###.#.#..#.#.#..###...#.#.#",
                ".#.#...#...#..#..#.....##.#...",
                "#..#.##..##..#.#..###.#....#.#",
                "..#..#..#...#...#....#..##.#..",
                "#..##..#..##.#.#.####..#.#...#",
                ".#....##.#.....#......##.#.#..",
                ".###.#...#.#.#..#.#.##...##.#.",
                ".....#.#.##..#.#..##...##...#.",
                "#.#.#...#...#.#.#...#.#.#.##.#",
                ".#..##.#..##..#.###...........",
                "..##.....####.......##.#.#.##.",
                "#....##.#.#...####.#...#.#.#..",
                "#.#.#......##.#...#..#.#..#..#",
                "..#..#.#.##...#.#..#..#..#..#.",
                ".#..#...#...#..#..#.#..#..#A#.",
                "..#..#.#.B##.##..#...#.#.##...",
                "#.#.##..#......#.#.#.#.#...#.#",
                "#.#...#.######...#.#.#.#.#.#..",
                "..#.##.#.....#.##..#...#.#.#.#",
                ".#..#..#.#.#.#.#..#.#####..#.#",
                "..#.#.##.#.#.##.#......#..#...",
                "#..#.....#.#.....#.#.##..##.#.",
                "##..###.#..#.#.#.#..##..#...##",
                "##.#...#..##.#.#..#.#..#.#.#..",
                "#..#.#.####..#..#..#..#......#",
                "..#..#.....####..#.##.#.###.#.",
                ".#..#.####.#.#..#.....#...#...",
                "..##.......#...#..####.##.#.#.",
                "#....#.#.#..#.###....#....#..#"
            };
            string moves[] = {
                "UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU",
                "RRUUURUULLD"
            };
            string __expected = "Alice wins";
            return do_test(to_vector(field), to_vector(moves), __expected, __no);
        }

        // Your custom testcase goes here
        case 6:
            break;
        default: break;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(2);
    cout << "GameInDarknessDiv2 (1000 Points)" << endl << endl;

    int nPassed = 0, nAll = 0;
    if (argc == 1)
        for (int i = 0; i < 6; ++i) nAll++, nPassed += run_testcase(i);
    else
        for (int i = 1; i < argc; ++i) nAll++, nPassed += run_testcase(atoi(argv[i]));
    cout << endl << "Passed : " << nPassed << "/" << nAll << " cases" << endl;

    int T = time(NULL) - 1413606889;
    double PT = T / 60.0, TT = 75.0;
    cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
    cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    return 0;
}
// CUT end
