class RideSharingSystem {
public:
    queue<int> driver;
    queue<int> rider;
    unordered_set<int> waiting;
    unordered_set<int> cancelled;
    RideSharingSystem() {}

    void addRider(int riderId) {
        rider.push(riderId);
        waiting.insert(riderId);
    }

    void addDriver(int driverId) { driver.push(driverId); }

    vector<int> matchDriverWithRider() {

        while (!rider.empty() && !cancelled.empty() &&
               (cancelled.find(rider.front()) != cancelled.end())) {

            int riderId = rider.front();
            rider.pop();
            cancelled.erase(riderId);
            waiting.erase(riderId);
        }

        if (!driver.empty() && !rider.empty()) {
            int riderId = rider.front();
            int driverId = driver.front();

            driver.pop();
            rider.pop();

            waiting.erase(riderId);

            return {driverId, riderId};
        }
        return {-1, -1};
    }

    void cancelRider(int riderId) {
        if (waiting.find(riderId) != waiting.end()) {
            cancelled.insert(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */