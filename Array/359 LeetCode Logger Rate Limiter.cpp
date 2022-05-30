// Link: https://leetcode.com/problems/logger-rate-limiter/

class Logger {
public:
    Logger() {

    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (!log.count(message) || log[message] + 10 <= timestamp) {
            log[message] = timestamp;
            return true;
        }
        return false;
    }
private:
    unordered_map<string,int> log;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */