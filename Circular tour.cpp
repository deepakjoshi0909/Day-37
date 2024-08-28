class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
      int st = 0;
      int track = 0;
      int rem = 0;
      
      for(int i=0;i<n;i++){
          rem = rem + (p[i].petrol - p[i].distance);
          
          if(rem < 0){
              st = i+1;
              track += rem;
              rem = 0;
          }
      }
      return rem + track >= 0? st : -1; 
    }
};
