int maxProfit(int MaxCap,int wt_of_obj[],int val_of_obj[],int no_of_obj){

	vector<vector<int>> ks(no_of_obj+1,vector<int>(MaxCap+1));
	//int ks[no_of_obj+1][MaxCap+1];
	//For choosing an object with respect to bag capacity we have two choices
	//1.Include:see step 1
	//2.Exclude:see step 2
	for(int curr_obj=0;curr_obj<=no_of_obj;++curr_obj)
	{
		for(int curr_cap=0;curr_cap<=MaxCap;++curr_cap){
			if(curr_cap==0 || curr_obj==0)
				ks[curr_obj][curr_cap]=0;
			//checks if current object's weight is less than curr bag capacity
			else if(wt_of_obj[curr_obj-1]<=curr_cap){
				//Step 1:include
				ks[curr_obj][curr_cap]
				=max(ks[curr_obj-1][curr_cap],val_of_obj[curr_obj-1]+ks[curr_obj-1][curr_cap-wt_of_obj[curr_obj-1]]);
			}
			else{//if above statement is false then we simply discard the current object
				//step 2:Exclude
				ks[curr_obj][curr_cap]=ks[curr_obj-1][curr_cap];
			}
		}
	}
	return ks[no_of_obj][MaxCap];
}
