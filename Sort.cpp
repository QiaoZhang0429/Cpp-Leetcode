class Solution{
public:
	//consider 0 ... i-1 already sorted, insert i in the right place
	//O(n^2), in-place
	void insertSort(vector<int>& nums){
		for(int i = 1; i < nums.size(); i++){
			if(nums[i] >= nums[i-1])
				continue;
			int toInsert = nums[i];
			int j;
			for(j = i-1; j >= 0 && nums[j] > toInsert; j--)
				nums[j+1] = nums[j];
			nums[j+1] = toInsert;
		}
	}

	//decreasing increment factor
	//complexity hard to say
	void shellSort(vector<int>& nums){
		int dk = nums.size() / 2;  
	    while(dk >= 1){  
	        shellInsertSort(nums, dk);  
	        dk = dk / 2;  
	    } 
	}

	void shellInsertSort(vector<int>& nums, int dk){
		for(int i = dk; i < nums.size(); i++){  
	        if(nums[i] < nums[i-dk]){        
	            int j = i-dk;     
	            int toInsert = nums[i];          
	            nums[i] = nums[i-dk];     
	            while(toInsert < nums[j]){    
	                nums[j+dk] = nums[j];  
	                j -= dk;            
	            }  
	            nums[j+dk] = toInsert;           
	        }  
    	}
	}

	//put the smallest at the beginning
	//O(n^2)
	void selectSort(vector<int>& nums){
		for(int i = 0; i < nums.size(); i++){
			int minKey = i;
			for(int j = i+1; j < nums.size(); j++){
				if(nums[j] < nums[minKey])
					minKey = j;
			}
			swap(nums[minKey], nums[i]);
		}
	}

	//O(nlogn)
	void heapSort(vector<int>& nums){
		priority_queue<int, vector<int>, less<int>> pq;
		for(auto n:nums)
			pq.push(n);
		int i = 0;
		while(!pq.empty()){
			nums[i] = pq.top();
			pq.pop();
		}
	}

	void heapSort(vector<int>& nums){
		buildHeap(nums);
		for(int i = nums.size()-1; i > 0; i--){
			swap(nums[i], nums[0]);
			heapAdjust(nums, 0, i);
		}
	}
	void buildHeap(vector<int>& nums){
		for(int i = (nums.size()-1) / 2; i >= 0; i--)
			heapAdjust(nums, i, nums.size());
	}
	void heapAdjust(vector<int>& H, int s, int length){  
	    int tmp  = H[s];  
	    int child = 2*s+1; //左孩子结点的位置。(i+1 为当前调整结点的右孩子结点的位置)  
	    while (child < length){  
	        if(child+1 <length && H[child]<H[child+1]){ // 如果右孩子大于左孩子(找到比当前待调整结点大的孩子结点)  
	            ++child ;  
	        }  
	        if(H[s]<H[child]){  // 如果较大的子结点大于父结点  
	            H[s] = H[child]; // 那么把较大的子结点往上移动，替换它的父结点  
	            s = child;       // 重新设置s ,即待调整的下一个结点的位置  
	            child = 2*s+1;  
	        }  
	        else             // 如果当前待调整结点大于它的左右孩子，则不需要调整，直接退出  
	             break;  
	        H[s] = tmp;         // 当前待调整的结点放到比其大的孩子结点位置上  
	    }
	}  

	//forward : bubble the biggest to the end
	//backward : bubble the smallest to the beginning
	//branch cut : stop when no swap happens, flag variable
	//O(n^2)
	void bubbleSort(vector<int>& nums){
		for(int i = 0; i < nums.size()-1; i++)
			for(int j = 0; j < nums.size()-i-1; j++)
				if(nums[j] > nums[j+1])
					swap(nums[j], nums[j+1]);
	}

	//pivot for separation
	//best average performance
	//O(nlogn)
	void quickSort(vector<int>& nums, int start, int end){
		if(start < end){
			int middle = partition(nums, start, end);
			quickSort(nums, start, middle-1);
			quickSort(nums, middle+1, end);
		}
	}
	int partition(vector<int>& nums, int start, int end){
		int pivot = nums[start];
		while(start < end){
			while(start < end && nums[end] >= pivot)
				end--;
			swap(nums[start], nums[end]);
			while(start < end && nums[start] <= pivot)
				start++;
			swap(nums[start], nums[end]);
		}
		return start;
	}
	int partition(vector<int>& nums, int start, int end){  
	    int pivot = A[end]; 
	    int i = start; 
	    for(int j = start; j < end; j++){  
	        if(nums[j] < pivot){  
	            swap(nums[i], nums[j]); 
	            i++;
	        }  
	    }  
	  	swap(nums[i], nums[end]);	  
	    return i;   
	}

	//O(nlogn)
	void mergeSort(vector<int>& nums, int start, int end){
		if(start < end){
			int middle = (start + end) / 2;
			mergeSort(nums, start, middle);
			mergeSort(nums, middle+1, end);
			merge(nums, start, middle, end);
		}
	}
	void merge(vector<int>& nums, int start, int middle, int end){
		int i = start, j = middle+1, k = start;
		vector<int> aux(nums.size(), 0);
		while(i <= middle && j <= end)
			aux[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
		while(i <= middle)
			aux[k++] = nums[i++];
		while(j <= end)
			aux[k++] = nums[j++];
		for(int k = start; k <= end; k++)
			nums[k] = aux[k];
	}

	//O(n+nlogn-nlogm)
	void radixSort(vector<int>& nums){
		for(auto n:nums)
			put n into corresponding radix
		sort each radix with any sorting algorithm
		merge all sorted radix
	}	
};

//http://blog.csdn.net/hguisu/article/details/7776068