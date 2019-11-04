#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int main() {
	//Number of queries
	int q;
	cin >> q;

	//For each query
	while(q--)
	{
	    //Create a set of integers in descending order, set means already sorted and unique elements
		set <int, greater <int> > corridor;4

		int n, r, shots = 0;
		cin >> n >> r;
		//Take Input Location of every monster, we will only be having unique values in the set, duplicated are ignored
		for(int i = 0 ; i < n ; i++)
		{
			int x;
			cin >> x;
			corridor.insert(x);
		}
        //Iterator is like pointer. We create a iterator which will iterator over a set
		 set <int, greater <int> > :: iterator itr;

        int cnt = 0;
        for (itr = corridor.begin(); itr != corridor.end(); ++itr)
        {
            int x = *itr;
            // x = element  pointed by iterator

            //if that element - range is less than 0, means he will be in trap, already dead
            //else we hit him, shot++ and move on
            if(x - (r*cnt++) > 0)
            {
                shots++;
                //cout << x;
            }
        }

        //answer
        cout << shots  << "\n";
	}
	return 0;
}
