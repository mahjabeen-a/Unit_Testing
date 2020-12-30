#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class Range {
 
    protected:
        int start;
        int end;
 
        void reset() {
           this -> start = 0;
           this -> end = 0;
            return;
        }
 
    public:
 
        Range() {
            this -> start = 0;
            this -> end = 0;
        }
 
        Range(int end) {
            this -> start = 0;
            this -> end = end;
        }
 
        Range(int start, int end) {
            this -> start = start;
            this -> end = end;
        }
 
        void rStretch(int n = 1) {
          this -> end += n;
        }  
 
        void lStretch(int n = 1) {
            this -> start -= n;
        }
 
        void stretch(int n = 1) {
            this -> start -= n;
            this -> end += n;
        }
 
        void squeeze(int n = 1) {
            this -> start += n;
            this -> end -= n;
 
            if (this -> start > this -> end)
                this -> reset();
        }
 
        void shift(int n = 1) {
            this -> start += n;
            this -> end += n;
        }
 
        int length() {
            return this -> end - this -> start + 1;
        }
 
        bool contains(int item) {
            return item >= this -> start && item <= this -> end;
        }
 
        bool equals(Range r) {
            return r.start == this -> start && r.end == this -> end;
        }
 
        bool isDisjoint(Range r) {
        	return this->start > r.end || this->end < r.start;
        }
 
        bool isOverlapping(Range r) {
            return (!this -> isDisjoint(r));
        }
 
        bool isTouching(Range r) {
            return this -> end + 1 == r.start || this -> start == r.end + 1;
        } 
 
        bool lessThan(Range r) {
            return this -> start < r.start;
        }
 
        bool greaterThan(Range r) {
            return this -> start > r.start;
        }
 
        bool isSubRange(Range r) {
            return this->start <= r.start && r.end <= this->end;
        }
 
        Range merge(Range r) {
            if (this->isDisjoint(r))
                return Range();
 
            else {
                return Range(min(this->start, r.start), max(this->end, r.end));
            }
        }
 
        Range common(Range r){
            if (this->isDisjoint(r))
                return Range();
 
            int arr[4] = {this->start, this->end, r.start, r.end};
            sort(arr, arr + 4);
 
            return Range(arr[1], arr[2]);
        }
 
        vector<int> elements() {
 
            vector<int> allInRange;
 
            for (int ele = this -> start; ele <= this -> end; ele++) 
                allInRange.push_back(ele);
 
            return allInRange;
        }
};
 
class ClosedRange: public Range {
 
    public:
 
        ClosedRange() {
            this -> start = 0;
            this -> end = 0;
        }
 
        ClosedRange(int end) {
            this -> start = 0;
            this -> end = end;
        }
 
        ClosedRange(int start, int end) {
            this -> start = start;
            this -> end = end;
        }
 
        string toString() {
            return "[" + to_string(this -> start) + ", " + to_string(this -> end) + "]";
        }
};
 
class OpenRange: public Range {
 
    public:
 
        OpenRange() {
            this -> start = 0;
            this -> end = 0;
        }
 
        OpenRange(int end) {
            this -> start = 0;
            this -> end = end - 1;
        }
 
        OpenRange(int start, int end) {
            this -> start = start + 1;
            this -> end = end - 1;
        }
 
        string toString() {
            return "(" + to_string(this -> start - 1) + ", " + to_string(this -> end + 1) + ")";
        }
};
 
class SemiOpenEnd: public Range {
 
    public:
 
        SemiOpenEnd() {
            this -> start = 0;
            this -> end = 0;
        }
 
        SemiOpenEnd(int end) {
            this -> start = 0;
            this -> end = end - 1;
        }
 
        SemiOpenEnd(int start, int end) {
            this -> start = start;
            this -> end = end - 1;
        }
 
        string toString() {
            return "[" + to_string(this -> start) + ", " + to_string(this -> end + 1) + ")";
        }
};
int main(){
	return 0;
}
