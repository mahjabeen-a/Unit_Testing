#include <algorithm>

using namespace std;

class Range {
		protected:
        int start, end;

        private:
        void reset(){
            start = end = 0;
        }

        public:
        Range(){
            start = end = 0;
        }

        Range (int limit) {
            start = 0, end = limit;
        }
        
        Range(int first, int last) {
            start = min(first, last);
            end = max(first, last);
        }
      
        int lengthOfRange() {
            return end - start + 1;
        }

        void rStretch(int n = 1){
            end += n;
        }
        
        void lStretch(int n = 1){
            start -= n;
        }

        void stretch(int n){
            start -= n;
            end += n;
        }

        void squeeze(int n){
            start += n;
            end -= n;
            if (start > end){
                this->reset();
            }
        }

        void shift(int n){
            start += n;
            end += n;
        }

        bool isSubRange(Range r) {
            return this->start <= r.start && r.end <= this->end;
        }
        
        bool contains(int val) {
            return this->start <= val && val <= this->end; 
        }
        
        bool isDisjoint(Range r){
            return this->start > r.end || this->end < r.start;
        }

        bool overlap(Range r) {
            return !(this->isDisjoint(r));
        }
        
        bool touching(Range r) {
            return ((r.start == this->end) || (this->start == r.end));
        }
        
        bool disjoint(Range r) {
            return (!overlap(r));
        }
        
        bool lessThan(Range r) { 
            return this->start < r.start || (this->start == r.start && this->lengthOfRange() < r.lengthOfRange());
        }
        
        Range merge(Range r) {
            if (this->disjoint(r))
                return Range();
            else {
                return Range(min(this->start, r.start), max(this->end, r.end));
            }
        }

        Range common(Range r){
            if (this->disjoint(r))
                return Range();
            int arr[4] = {this->start, this->end, r.start, r.end};
            sort(arr, arr + 4);
            return Range(arr[1], arr[2]);
        }
};


