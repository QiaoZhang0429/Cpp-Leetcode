//initialize number generator -- helo wuth truly random
srand(time(NULL))
srand(1)
//pseudo-random integer between 0 and RAND_MAX
rand()
//generate random integer in certain range
//this operation makes lower numbers slightly more likely
output = min + (rand() % (int)(max - min + 1))
//random float [0,1]
float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
//random header
std::random_device rd;
// Engines 
std::mt19937 e2(rd());//std::knuth_b e2(rd());//std::default_random_engine e2(rd()) ;
// Distribtuions
std::uniform_real_distribution<> dist(0, 10);//std::normal_distribution<> dist(2, 2);//std::student_t_distribution<> dist(5);//std::poisson_distribution<> dist(2);//std::extreme_value_distribution<> dist(0,2);
std::map<int, int> hist;
for (int n = 0; n < 10000; ++n) {
    ++hist[std::floor(dist(e2))];
}

//randomly pick
index = rand() % nums.size();
//randomly pick - replace with probability of 1/count
int index = -1;
for(int i = 0 ; i < nums.size(); i++){
    if(nums[i] != target)
        continue;
    count++;
    if(index == -1 || ((rand() % count) == 0))
        index = i;
}
//weighted random number + generate new array and uniformly random pick
//weighted random number + binary search
int sum_of_weight = 0;
for(int i=0; i<num_choices; i++) {
   sum_of_weight += choice_weight[i];
}
int rnd = random(sum_of_weight);
for(int i=0; i<num_choices; i++) {
  if(rnd < choice_weight[i])
    return i;
  rnd -= choice_weight[i];
}
//randomly pick k form data stream
vector<int> picked(k, -1);
for(int i = 0 ; i < nums.size(); i++){
	if(i < k){
		picked.push_back(nums[i]);
		continue;
	}
	int M = rand() % (i+1);//[0, i]
	if(M < k)
		picked[M] = nums[i];
}