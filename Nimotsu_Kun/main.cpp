#include<iostream>
#include<string>
#define P pair<int, int>

using namespace std;

const int H = 5, W = 8, O = 2;
string stage[H+1];
char command;
P player;


void initStage(){
  int cnt_o = 0;
  stage[0] = "########";
  stage[1] = "# .. p #";
  stage[2] = "# oo   #";
  stage[3] = "#      #";
  stage[4] = "########";

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(stage[i][j] == 'p'){
        player = P(i, j);
        stage[i][j] = ' ';
      }
    }
  }
}

void getInput(){
  command = ' ';
  cout << "a:left s:right w:up z:down. command? ";
  cin >> command;
}

void updateGame(){
  int cur_y = player.first, cur_x = player.second;
  int dy = 0, dx = 0;
  if(command == 'a')dx = -1;
  if(command == 's')dx = 1;
  if(command == 'w')dy = -1;
  if(command == 'z')dy = 1;
  int ny = cur_y + dy, nx = cur_x + dx;
  int nny = ny + dy, nnx = nx + dx;
  if(stage[ny][nx] == 'O'){
    if(stage[nny][nnx] == ' '){
      stage[nny][nnx] = 'o';
      stage[ny][nx] = '.';
      player = P(ny, nx);
    }
    if(stage[nny][nnx] == '.'){
      stage[nny][nnx] = 'O';
      stage[ny][nx] = '.';
      player = P(ny, nx);
    }
    return;
  }
  if(stage[ny][nx] == 'o'){
    if(stage[nny][nnx] == ' '){
      stage[nny][nnx] = 'o';
      stage[ny][nx] = ' ';
      player = P(ny, nx);
    }
    if(stage[nny][nnx] == '.'){
      stage[nny][nnx] = 'O';
      stage[ny][nx] = ' ';
      player = P(ny, nx);
    }
    return;
  }
  if(stage[ny][nx] == ' ' || stage[ny][nx] == '.'){
    player = P(ny, nx);
    return;
  }
}

void draw(){
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(i == player.first && j == player.second){
        if(stage[i][j] == '.')cout << 'P';
        else cout << 'p';
      }
      else cout << stage[i][j];
    }
    cout << endl;
  }
}

int main(){
  initStage();
  draw();
  while(1){
    getInput();
    updateGame();
    draw();
  }
}