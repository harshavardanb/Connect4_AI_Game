#include <iostream>
#include <ctime>

#include "MinmaxAB.h"
#include "TreeNodes.h"
#include "ConnectFourBoard.h"
#include "AlphaBeta.h"
using namespace std;

/*variable that can be accessed by files
  TreeNodes.h and .cpp, and main function
*/
int num_nodes_generated, num_nodes_expanded,game_path_length,start_time,stop_time;

/*made as a global variable since it must be accessible to
  Minmax() fn and also AlphaBeta() fn
*/
char evalfn_choice;

/* for calling minmaxAB function
   creates a tree object,board object and minmaxab object
   using a while loop keeps calling the minmaxAB function
   repeatedly until the condition checkPlayerWon evaluates
   to true. */
void MinMax(){

   int moves_made = 0;
   tic *board_ob = new tic;

   cout<<endl;
   cout<<"initial board state before starting game with(Initial Node config/Root Node) "<<moves_made<<" moves made"<<endl;
   cout<<"---------------------------------------------------------"<<endl;

   board_ob->display_board(board_ob);
   board_ob->player = 'X';

   start_time = clock();
    while(!board_ob->checkPlayerWon()){

        tree *head = new tree;
        *(head->ob) = *board_ob;

        if(head->ob->isBoardEmpty()){

            int random_col_index = head->ob->makeFirstMove();
            head->ob->board[0][random_col_index] = 'X';
            head->ob->player = 'X';
            moves_made++;
            game_path_length++;
            cout<<"After 1st move board state(Max's move/Root Node):"<<endl;
            head->ob->display_board(head->ob);
        }

        minmaxA min_ob;
        //assigns the users choice of evaluation function chosen
        min_ob.eval_choice = evalfn_choice;
        int x = min_ob.minmaxAB(head,0,1000,-1000,head->ob->player);
        moves_made++;
        game_path_length++;

        //to get the optimal node - Move Gen function
        head->move_gen(board_ob,moves_made);
    }
    stop_time = clock();
}

/* for calling AlphaBeta function
   creates a tree object,board object and alphabeta object
   using a while loop keeps calling the alphabeta function
   repeatedly until the condition checkPlayerWon evaluates
   to true. */
void AlphaBeta(){

   int moves_made = 0;

   tic *board_ob = new tic;

   cout<<endl;
   cout<<"initial board state before starting game with(Initial Node config/Root Node) "<<moves_made<<" moves made"<<endl;
   cout<<"---------------------------------------------------------"<<endl;

   board_ob->display_board(board_ob);
   board_ob->player = 'X';

   start_time = clock();
   while(!board_ob->checkPlayerWon()){

        tree *head = new tree;
        *(head->ob) = *board_ob;

        if(head->ob->isBoardEmpty()){

            int random_col_index = head->ob->makeFirstMove();
            head->ob->board[0][random_col_index] = 'X';
            head->ob->player = 'X';
            moves_made++;
            game_path_length++;
            cout<<"After 1st move board state(Max's move/Root Node):"<<endl;
            head->ob->display_board(head->ob);
        }

        alphabeta ab_ob;
        //assigns the users choice of evaluation function chosen
        ab_ob.eval_choice = evalfn_choice;
        int x = ab_ob.alpha_beta(head,0,head->ob->player,1000,-1000);
        moves_made++;
        game_path_length++;

        //to get the optimal node - Move Gen function
        head->move_gen(board_ob,moves_made);
   }
   stop_time = clock();
}

int main()
{
    int algo_choice;
    cout<<"Select Algorithm and evaluation function to play the game with ?"<<endl;
    cout<<endl;
    cout<<"  1 - MinmaxAB"<<endl;
    cout<<"  2 - AlphaBeta"<<endl;
    cout<<endl;
    cin>>algo_choice;
    cout<<endl;

    cout<<"  M/m - Madhusudhan's eval function"<<endl;
    cout<<"  H/h - Harsha's eval function"<<endl;
    cout<<"  S/s - Santosh's eval function"<<endl;
    cout<<endl;
    cin>>evalfn_choice;
    cout<<endl;


    char final_choice;
    //for my final_choice
    if((algo_choice == 1) && (evalfn_choice == 'M' || evalfn_choice == 'm'))
        final_choice = 'A';

    if((algo_choice == 2) && (evalfn_choice == 'M' || evalfn_choice == 'm'))
        final_choice = 'B';


    //for Harsha final_choice
    if((algo_choice == 1) && (evalfn_choice == 'H' || evalfn_choice == 'h'))
        final_choice = 'C';

    if((algo_choice == 2) && (evalfn_choice == 'H' || evalfn_choice == 'h'))
        final_choice = 'D';


    //for Santosh final_choice
    if((algo_choice == 1) && (evalfn_choice == 'S' || evalfn_choice == 's'))
        final_choice = 'E';

    if((algo_choice == 2) && (evalfn_choice == 'S' || evalfn_choice == 's'))
        final_choice = 'F';


    switch(final_choice){

    case 'A':
        MinMax();
        break;

    case 'B':
        AlphaBeta();
        break;


    case 'C':
        MinMax();
        break;

    case 'D':
        AlphaBeta();
        break;


    case 'E':
        MinMax();
        break;

    case 'F':
        AlphaBeta();
        break;

    default:
        cout<<"No case matched! Please select options properly."<<endl;
    }

  return 0;
}

