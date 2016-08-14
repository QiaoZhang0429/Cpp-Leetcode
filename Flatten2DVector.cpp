class Vector2D { 
private:
     vector<vector<int>>::iterator x, xEnd;
     vector<int>::iterator y;
public:  
    Vector2D(vector<vector<int>>& vec2d) {  
        x = vec2d.begin();
        xEnd = vec2d.end();
        y = (*x).begin();
    }  
  
    int next() {  
        return *y++;
    }  
  
    bool hasNext() {  
        while(x != xEnd && y == (*x).end()){
            x++;
            y = (*x).begin();
        }
        return x != xEnd;
    }   
};  
  
/** 
 * Your Vector2D object will be instantiated and called as such: 
 * Vector2D i(vec2d); 
 * while (i.hasNext()) cout << i.next(); 
 */  