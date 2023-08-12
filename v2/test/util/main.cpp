#include "main.h"

int main() {
    Test("Deque push back: ", Test_deque_push_back);
    Test("Deque pop front: ", Test_deque_pop_front);
    Test("Deque remove: ", Test_deque_remove);
    Test("Deque remove index: ", Test_deque_remove_index);
    Test("Deque access operator: ", Test_deque_access_operator);
    Test("Deque size: ", Test_deque_size);
    Test("Deque iter: ", Test_deque_iter);
    Test("Deque filter: ", Test_deque_filter);

    Test("Data manager timer: ", Test_data_manager_timer);
    Test("Data manager cash: ", Test_data_manager_cash);
    return 0;
}
