#include <iostream>
#include <deque>
#include <queue>
using namespace std;

#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

int main() {
    int board[101][101] = { 0, }; //0:NOTHING, 1:APPLE, 2:SNAKE
    queue<pair<int,char>> route;
    int N, K, row, column, L, X;
    char C;

    scanf("%d %d", &N, &K);
    for (int i=0; i<K; i++) {
        scanf("%d %d", &row, &column);
        board[row][column] = 1;
    }
    scanf("%d", &L);
    for (int i=0; i<L; i++) {
        scanf("%d %c", &X, &C);
        route.push({X,C});
    }

    deque<pair<int,int>> snake;
    //게임이 시작할 때 뱀은 맨위 맨좌측에 위치
    int x = 1, y = 1;
    snake.push_back({y,x}); 
    int direction = RIGHT; //뱀은 처음에 오른쪽을 향한다
    int time = 0;
    while (1) {
        if (direction == RIGHT) { x++; }
        else if (direction == DOWN) { y++; }
        else if (direction == LEFT) { x--; }
        else if (direction == UP) { y--; }
        time++;

        if (x<1 || x>N || y<1 || y>N || board[y][x] == 2) {
            //벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다
            break;
        }
        else if (board[y][x] == 1) {
            //만약 이동한 칸에 사과가 있다면
            board[y][x] = 2; //그 칸에 잇던 사과가 없어지고
            snake.push_front({y,x}); //꼬리는 움직이지 않는다
        }
        else {
            //만약 이동한 칸에 사과가 없다면
            board[y][x] = 2;
            snake.push_front({y,x}); 

            //몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; 
            snake.pop_back();
        }

        if (route.front().first == time) {
            if (route.front().second == 'L') {
                direction = (direction + 3) % 4;
            }
            else if (route.front().second == 'D') {                
                direction = (direction + 1) % 4;
            }
            route.pop();
        }
    }

    printf("%d", time);

    return 0;
}