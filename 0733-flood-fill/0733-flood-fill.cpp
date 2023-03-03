class Solution {
public:
    bool isvalid(vector<vector<int>>& image, int i, int j,int n,int m, int color){
        if(i>=0 && j>=0 && i<n && j<m && image[i][j] == color)
            return true;
        
        return false;
        
    }
   void floodFillRec(vector<vector<int>>& image, int sr, int sc,int n,int m,int oldcolor, int color){
         image[sr][sc] = color;
        
        if(isvalid(image,sr+1,sc, n, m,oldcolor)) 
         floodFillRec(image,sr+1,sc,n,m,oldcolor,color);
        
         if(isvalid(image,sr-1,sc, n,m,oldcolor)) 
         floodFillRec(image,sr-1,sc,n,m,oldcolor,color);
        
         if(isvalid(image,sr,sc+1, n,m,oldcolor)) 
         floodFillRec(image,sr,sc+1,n,m,oldcolor,color);
        
         if(isvalid(image,sr,sc-1,n,m,oldcolor)) 
         floodFillRec(image,sr,sc-1,n,m,oldcolor,color);
             
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int oldcolor = image[sr][sc];
        
        if(oldcolor == color) return image;
        
        floodFillRec(image,sr,sc,n,m,oldcolor,color);
        
        return image;
    }
};