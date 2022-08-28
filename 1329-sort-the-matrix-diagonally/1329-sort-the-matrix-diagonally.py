class Solution {
    public int[][] diagonalSort(int[][] mat) {
        int m = mat.length, n = mat[0].length;
    HashMap<Integer,PriorityQueue<Integer>>Map = new HashMap<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                Map.putIfAbsent(i-j,new PriorityQueue<>());
                Map.get(i-j).add(mat[i][j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = Map.get(i-j).peek();
                Map.get(i-j).poll();
            }
        }
        
        return mat;
    }
}