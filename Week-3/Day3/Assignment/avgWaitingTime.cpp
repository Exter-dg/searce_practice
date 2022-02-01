// which job to choose?
// - will it depend on the time since they are waiting also?
// - or only on the time required to do the job

// intuition

// If there are 2 jobs currently, both came at the same time
// so doesn't matter the time since they are waiting (as it is same)
// In this case, choosing the one with shorter duration is beneficial
// duration of job a = x , job b = y, such that x>y
// If (a->b) then avg waiting time will be f(x + (x+y))
// if (b->a) then avg waiting time will be f(y + (y+x))

// ------------------------------------------------------------

// if there are 2 jobs, a and b, both have separate waiting times
// even in this case, we will still choose the job with the shortest duration
// lets say job a waited p mins and job b waited q mins.
// duration of job a = x , job b = y

// if (a->b) avg waiting time will be f(Execute A -> Execute B) =
// Execute A = p (waiting time previous) + x(duration)
// Exectue B = q (wauting time previous) + x(waiting time current due to A) + y(duration)
// avg time = f(p+x + q+x+y)

// if (b->a)
// Execute B = q + y
// Execute A = p + y + x
// avg time = f(q+y + p+y+x)

// p and q are in both formulas (ONCE only). The time depends only upon x and y
// hence whichever is smaller should be executed first to decrease overall time

//  ------------------------------------------------------------------------------
// Code

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

bool myCompare(pi a, pi b) {
    if (a.second < b.second)
        return true;
    else if (a.second > b.second)
        return false;
    else {
        if (a.first < b.first)
            return true;
        else
            return false;
    }
}

ll avgWaitingTime(vector<pi> time) {

    ll totalTime = 0, currTime = 0;

    // min heap priority queue
    // shortest order will be first
    priority_queue<pi, vector<pi>, greater<pi>> pq;

    while (!time.empty() || !pq.empty()) {

        // if pq is empty(no tasks to execute) and no new tasks have arrived
        // set current time as the arrival of next order
        if (pq.empty() && currTime < time[0].second)
            currTime = time[0].second;

        // add arrived(till currTime) orders to pq for processing
        while (!time.empty() && time[0].second <= currTime) {
            pq.push(time[0]);
            time.erase(time.begin());
        }

        // total time = waiting + time required for execution
        totalTime += (currTime - pq.top().second) + pq.top().first;

        // update current time
        currTime += pq.top().first;
        pq.pop();
    }

    return totalTime;
}

int main() {
    ll n;
    cin >> n;
    ll t, l;
    vector<pi> time;

    for (ll i = 0; i < n; i++) {
        cin >> t >> l;
        // store as l, t (easy to sort in priority queue later on)
        time.push_back({l, t});
    }

    // sort in increasing order of arrival (second parameter)
    sort(time.begin(), time.end(), myCompare);

    // cout << "The average waiting time: " << avgWaitingTime(time)/time.size();
    cout << avgWaitingTime(time) / time.size();
    return 0;
}
