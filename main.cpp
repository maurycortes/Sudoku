//
//  main.cpp
//  Sudoku
//
//  Created by Victor Elizalde on 21/09/15.
//  Copyright (c) 2015 Victor Elizalde. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool Check (int imatriz[9][9], int h, int k, int l, int m)
{
    bool bCheck = true;
    int iarr[9], iren = 0, icol = 1;
    for(int i = h; i<l; i++)
    {
        for(int j = k; j<m; j++)
        {
            iarr[iren] = imatriz[i][j];
            iren++;
        }
    }

        for(int i = 0; i<9; i++)
        {
            icol = i+1;
            do{
                if(iarr[i] == iarr[icol])
                bCheck = false;
                icol++;
            }while(icol == 9);
            
        }

    return bCheck;
}

int main()
{
    int imatriz[9][9], inum, icol = 1, iren = 1;
    bool bCheck1, bCheck2, bCheck3, bCheck4, bCheck5, bCheck6, bCheck7, bCheck8, bCheck9, bCheck10 = true, bCheck11 = true;
    srand (time(NULL));
    
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            cin >> inum;
            imatriz[i][j] = inum;
        }
    }
    
    bCheck1 = Check(imatriz, 0, 0, 3, 3);
    bCheck2 = Check(imatriz, 0, 3, 3, 6);
    bCheck3 = Check(imatriz, 0, 6, 3, 9);
    bCheck4 = Check(imatriz, 3, 0, 6, 3);
    bCheck5 = Check(imatriz, 3, 3, 6, 6);
    bCheck6 = Check(imatriz, 3, 6, 6, 9);
    bCheck7 = Check(imatriz, 6, 0, 9, 3);
    bCheck8 = Check(imatriz, 6, 3, 9, 6);
    bCheck9 = Check(imatriz, 6, 6, 9, 9);
    
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<8; j++)
        {
            icol = j+1;
            do{
                if(imatriz[i][j] == imatriz[i][icol])
                bCheck10 = false;
                icol++;
            }while(icol != 9);
        }
    }
    
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j<8; j++)
        {
            iren = j+1;
            do{
                if(imatriz[j][i] == imatriz[iren][i])
                    bCheck11 = false;
                iren++;
            }while(iren != 9);
        }
    }

    if(bCheck1 && bCheck2 && bCheck3 && bCheck4 && bCheck5 && bCheck6 && bCheck7 && bCheck8 && bCheck9 && bCheck10 && bCheck11)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    
    
    return 0;
}

