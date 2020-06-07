#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std;

bool sanitycheck(vector<vector<int> > &orig){
  for (int row =0; row < orig.size()-1; row++){
    for(int col = 0; col<orig[row].size()-1; col++){
      if(orig[row][col] >= orig[row+1][col] || orig[row][col] >= orig[row][col+1])
	{
	  return false;
	}

      if(orig[row+1][col]!=0 && orig[row][col+1]!=0){
	if(orig[row+1][col]%2 == orig[row][col+1]%2)
	  {
	    return false;
	  }
      }

      if(orig[row][col]!=0 && orig[row+1][col+1]!=0){
	if(orig[row][col]%2 == orig[row+1][col+1]%2)
	  {
	    return false;
	  }
      }
    }
  }
  int x = orig.size();
  int y = orig[0].size();

  for(int i=0; i<x-1; i++){
    //check last col
    if(orig[i][y-1]>=orig[i+1][y-1])
      return false;
  }

  for(int j=0; j<y-1;j++){
    //check last row
    if(orig[x-1][j]>=orig[x-1][j+1])
      return false;
  }
  return true;
}

long fillin(vector<vector<int> > &orig){

  vector<vector<int> > p1=orig;
  vector<vector<int> > p2=orig;
  vector<vector<int> > p3=orig;
  vector<vector<int> > p4=orig;
  
  long result1 = 0;
  long result2 = 0;
  long result3 = 0;
  long result4 = 0;
  
  for (int row =0; row < orig.size(); row++){
    for(int col = 0; col<orig[row].size(); col++){
      if (orig[row][col]==0)
        {
          if(row == 0 && col==0)
            {
              p1[row][col] = 1;
	      p3[row][col] = 1;
	      p2[row][col] = 2;
	      p4[row][col] = 2;
            }
          else if(row == 0)
            {
              p1[row][col] = p1[row][col-1]+1;
	      p3[row][col] = p3[row][col-1]+2;
	      p2[row][col] = p2[row][col-1]+1;
	      p4[row][col] = p4[row][col-1]+2;
            }
          else if(col == 0)
            {
              p1[row][col] = p1[row-1][col]+2;
	      p3[row][col] = p3[row-1][col]+1;
	      p2[row][col] = p2[row-1][col]+2;
	      p4[row][col] = p4[row-1][col]+1;
            }
          else
            {
	      if(p1[row-1][col]>p1[row][col-1])
		{
		  p1[row][col] = p1[row-1][col]+2;
		}
	      else
		{
		  p1[row][col] = p1[row][col-1]+1;
		} 
	      if(p2[row-1][col]>p2[row][col-1])
		{
		  p2[row][col] = p2[row-1][col]+2;
		}
	      else
		{
		  p2[row][col] = p2[row][col-1]+1;
		}
	      if(p3[row-1][col]>p3[row][col-1])
		{
		  p3[row][col] = p3[row-1][col]+1;
		}
	      else
		{
		  p3[row][col] = p3[row][col-1]+2;
		}

	      if(p4[row-1][col]>p4[row][col-1])
		{
		  p4[row][col] = p4[row-1][col]+1;
		}
	      else
		{
		  p4[row][col] = p4[row][col-1]+2;
		}
     
	    }
	}
      result1 += p1[row][col];
      result2 += p2[row][col];
      result3 += p3[row][col];
      result4 += p4[row][col];
    }
  }
 
  if(sanitycheck(p1)==false)
    result1 = -1;
  if(sanitycheck(p2)==false)
    result2 = -1;
  if(sanitycheck(p3)==false)
    result3 = -1;
  if(sanitycheck(p4)==false)
    result4 = -1;
  /*
  vector<long> x;
  x.push_back(result1);
  x.push_back(result2);
  x.push_back(result3);
  x.push_back(result4);
  sort(x.begin(),x.end());
  for(int o=0; o<4; o++){
    if(x[o]>0){
      return x[o];
    }   
  }
  */


  priority_queue <int> pq;
  if(result1!=-1)
    pq.push(result1);
  if(result2!=-1)
    pq.push(result2);
  if(result3!=-1)
    pq.push(result3);
  if(result4!=-1)
    pq.push(result4);

  if(pq.empty()==true)
    return -1;
  else
    return pq.top();
}

int main() {
  ios_base::sync_with_stdio(false);
  int row;
  int col;
  cin>>row;
  cin>>col;
  vector<vector<int> > input;
  for(int i=0; i<row; i++)
    {
      vector<int> temprow;
      for(int j = 0; j<col; j++)
        {
          int temp;
          cin>>temp;
          temprow.push_back(temp);
        }
      input.push_back(temprow);
    }

  cout<<fillin(input);
  return 0;
}
