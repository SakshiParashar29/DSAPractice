// if a 0 0 0, each zero represents don't take that number and 1 represents take that number

// given nums array and size of array is n

for(int i = 0; i < 2^n; i++){
  for(int mask = 0; mask < n; mask++){
     if(i && (1 << mask){
       sum += nums[mask];
     }
  }
  subsetSum.push_back(sum);
}
