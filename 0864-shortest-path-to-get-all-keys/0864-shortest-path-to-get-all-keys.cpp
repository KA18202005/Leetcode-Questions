class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int sx, sy;
        int keys = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='@'){
                    sx=i;
                    sy=j;
                }
                if(grid[i][j]>='a' && grid[i][j]<='f') keys++;
            }
        }
        int target=(1<<keys)-1;
        queue<vector<int>> q;
        q.push({sx,sy,0});
        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n,vector<int>(64,0)));
        vis[sx][sy][0]=1;
        int steps=0;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto cur=q.front();
                q.pop();
                int x=cur[0];
                int y=cur[1];
                int mask=cur[2];
                if(mask==target) return steps;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx<0||ny<0||nx>=m||ny>=n) continue;
                    char ch=grid[nx][ny];
                    if(ch=='#') continue;
                    int newMask=mask;
                    if(ch>='a' && ch<='f') newMask|=(1<<(ch-'a'));
                    if(ch>='A' && ch<='F'){
                        if(!(newMask&(1<<(ch-'A')))) continue;
                    }
                    if(!vis[nx][ny][newMask]){
                        vis[nx][ny][newMask]=1;
                        q.push({nx,ny,newMask});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};