void backtrack(int x, int row){
    // Ta đánh dấu cột A, B, C là 0, 1, 2
    // a[x] là vị trí hiện tại của đĩa x
    if (a[x] == row){ // đĩa x đang ở đúng vị trí nó cần được chuyển sang
       backtrack(x - 1, row);
    }
    else{
       // chuyển x - 1 đĩa sang cọc trung gian
       backtrack(x - 1, 3 - row - a[x]);
       // thực hiện chuyển đĩa x sang cọc cần được chuyển sang
       a[x] = row
       // chuyển x - 1 đĩa sang cọc cần được chuyển sang
       backtrack(x - 1, row);
    }
}
