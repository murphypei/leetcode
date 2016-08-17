// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Rectangle Area
// Assume that the total area is never beyond the maximum possible value of int.


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // C > A, G > E, D > B, H > F
        int cover_width = getOverlappedLen(A, C, E, G);
        int cover_height = getOverlappedLen(B, D, F, H);
        return abs(A-C) * abs(B-D) + abs(E-G)*abs(F-H) - cover_width * cover_height;
    }
    
    
    inline int getOverlappedLen(int low1, int high1, int low2, int high2) {
        if(low2 > high1 || low1 > high2)
            return 0;
        else
            return min(high1, high2) - max(low1, low2);
    }
};