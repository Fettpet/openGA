// This library is free and distributed under
// Mozilla Public License Version 2.0.

#include <openGA.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct MySolution {
    std::vector<double> x;
    std::string to_string() const;
};

struct MyMiddleCost {
    // This is where the results of simulation
    // is stored but not yet finalized.
    double cost;
};

using GaType = EA::Genetic<MySolution, MyMiddleCost>;
using GenerationType = EA::GenerationType<MySolution, MyMiddleCost>;

void init_genes(MySolution& p, const std::function<double(void)>& rnd01);

bool eval_solution(const MySolution& p, MyMiddleCost& c);

MySolution mutate(const MySolution& X_base, const std::function<double(void)>& rnd01, double shrink_scale);

MySolution crossover(const MySolution& X1, const MySolution& X2, const std::function<double(void)>& rnd01);

double calculate_SO_total_fitness(const GaType::ThisChromosomeType& X);

void SO_report_generation(
    int generation_number,
    const EA::GenerationType<MySolution, MyMiddleCost>& last_generation,
    const MySolution& best_genes);

struct TestResult {
    double duration;
    string title;

    TestResult(double duration, string title)
        : duration(duration)
        , title(title) {}
};

void run_test(bool multi_threading, bool dynamic_threading, int idle_delay_us, string title);

void main1();
void main2();
void main3();
