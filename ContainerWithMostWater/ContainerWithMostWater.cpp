int MAX(int a, int b){return a > b ? a : b}
int MIN(int a, int b){return a < b ? a : b}

class Solution 
{
public:
    vector<int> maxArea(vector<int>& nums) 
    {
       int len = nums.size(), low = 0, high = len -1;
       int maxArea = 0;  
       while (low < high) 
			 {
         maxArea = MAX(maxArea, (high - low) * MIN(height[low], height[high]));  
         if (height[low] < height[high]) 
				 {
				   low++;
				 } 
				 else 
				 {
				   high--;
				 }
       }  
       return maxArea;  
    }
};
