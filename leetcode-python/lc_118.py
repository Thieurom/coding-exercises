class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        
        rows = []
        for _ in range(numRows):
            row = rows[-1] if len(rows) > 0 else []
            rows.append(self._nextRow(row))
            
        return rows
            
        
    def _nextRow(self, row: List[int]) -> List[int]:
        next_row = [1] * (len(row) + 1)
        
        for i in range(1, len(row)):
            next_row[i] = row[i-1] + row[i]
            
        return next_row
