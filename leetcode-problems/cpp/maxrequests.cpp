int maximumRequests(int window, vector<int> timestamps) {


// we can use a left- to right algo/method

// a edge case if vector is empty
if (timestamps.size() == 0) {
    return 0;
}

int left = 0; // left boundary tracker
int res = 0; //tracker for best response

// need to move the right pointer (right) along to increase window
for (int right = 0; right < timestamps.size(); ++right) {
    // need to shring window from left to right until it hits the window size 
    // it has to be window size - 1, so it can't even equal window size
    while (timestamps[right] - timestamps[left] >= window) { 
        ++left;
    }
    
    // place holder for what current is
    int curr_largest = right - left + 1; // account we are dealing with positioning of a vector
    
    // so dealing with a max that can change in this method we can use max func that declares which number is larger and makes it new max
    res = std::max(res, curr_largest);
}

// want to return an int that is the "max number of reqs ever given"
return res;

}
