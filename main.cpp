// -*- C++ -*-
//===--------------------------- Q-Learning ---------------------------------===//
//
//                     C++ Version of Q-Learning
//
// This file implements an simple C++ Q-Learning algorithm
// Author is Jin Fagang.
//
//===----------------------------------------------------------------------===//
#include <iostream>
#include <string>
#include <string.h>
#include "utils/utils.h"

using namespace std;

// I think Q matrix and R matrix must be same
// and it must be same both row and column
#define MATRIX_ROW 6
#define MATRIX_COLUMN 6
// state num must be equal to action num
#define STATE_NUM 6
#define ACTION_NUM 6
#define DES_STATE 5
#define MAX_EPISODE 1000
// this value using for Q(s,a)=R(s,a)+alpha * max{Q(s', a')}
// Q(s', a') is the all next step Q value
#define alpha 0.8

// define the most important Q-matrix and R-matrix
// R-matrix is given
double R[100][100] = {{-1, -1, -1, -1, 0, -1},
                     {-1, -1, -1, 0, -1, 100},
                     {-1, -1, -1, 0, -1, -1},
                     {-1, 0, 0, -1, 0, -1},
                     {0, -1, -1, 0, -1, 100},
                     {-1, 0, -1, -1, 0, 100}};
double Q[100][100];
int possible_action[10];
int possible_action_num;


// get in state s, possible actions
void get_possible_action(double R[100][100], int state, int possible_action[10]){
    // find R[i][j] value > 0 is action we can do later
    possible_action_num = 0;
    for(int i = 0; i < ACTION_NUM; i++){
        if (R[state][i] >= 0){
            possible_action[possible_action_num] = i;
            possible_action_num++;
        }
    }
}
double get_max_q(double Q[100][100], int state){
    double temp_max = 0;
    for (int i = 0; i < ACTION_NUM; ++i) {
        if ((R[state][i] >= 0) && (Q[state][i] > temp_max)){
            temp_max = Q[state][i];
        }
    }
    return temp_max;
}
int episode_iterator(int init_state, double Q[100][100], double R[100][100]){

    double Q_before, Q_after;
    // next action
    int next_action;
    double max_q;

    // start series event loop
    int step=0;
    while (1){
        cout << "-- step " << step << ": initial state: " << init_state << endl;
        // memset possible_action array
        memset(possible_action, 0, 10*sizeof(int));
        get_possible_action(R, init_state, possible_action);

        // get next action
        next_action = possible_action[rand()%possible_action_num];
        cout << "-- step " << step << ": next action: " << next_action << endl;
        // treat next action as state, and we can get max{Q(s', a')}
        max_q = get_max_q(Q, next_action);

        Q_before = Q[init_state][next_action];
        // update formula Q(s,a)=R(s,a)+alpha * max{Q(s', a')}
        Q[init_state][next_action] = R[init_state][next_action] + alpha * max_q;
        Q_after = Q[init_state][next_action];

        // next episode rules
        // if next_action is destination state, then go next episode
        // if not, then go back to this loop
        if (next_action == DES_STATE){
            init_state = rand()%STATE_NUM;
            break;
        }else{
            // if not destination state, then next action becomes initial state
            init_state = next_action;
        }
        step++;
    }
    return init_state;
}

int inference_best_action(int now_state, double Q[100][100]){
    // get the max value of Q corresponding action when state is nw_state
    double temp_max_q=0;
    int best_action=0;
    for (int i = 0; i < ACTION_NUM; ++i) {
        if (Q[now_state][i] > temp_max_q){
            temp_max_q = Q[now_state][i];
            best_action = i;
        }
    }
    return best_action;
}
void run_training(int init_state){
    int initial_state = init_state;

    // start random
    srand((unsigned)time(NULL));
    cout << "[INFO] start training..." << endl;
    for (int i = 0; i < MAX_EPISODE; ++i) {
        cout << "[INFO] Episode: " << i << endl;
        initial_state = episode_iterator(initial_state, Q, R);
        cout << "-- updated Q matrix: " << endl;
        print_matrix(Q, 6, 6);
    }
}

int main() {

    cout << "Q matrix:" << endl;
    print_matrix(Q, 6, 6);
    cout << "R matrix:" << endl;
    print_matrix(R, 6, 6);

    run_training(1);
    cout << "Q convergence matrix:" << endl;
    print_matrix(Q, 6, 6);

    int position;
    while (1){
        cout << "please input robot locate room: " << endl;
        cin >> position;
        cout << position << "->";
        while (1){
            int best_action = inference_best_action(position, Q);
            cout << best_action << "->";
            if (best_action == DES_STATE){
                cout << "out" << endl;
                break;
            }else{
                position = best_action;
            }
        }
    }

    return 0;
}