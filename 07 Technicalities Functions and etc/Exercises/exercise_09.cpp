//
// Created by consent_ on 09-Mar-25.
//
//Write a function that given two vector<double>s price
// and weight computes a value (an ‘‘index’’) that is the sum of all price[i]∗weight[i].
// Make sure to have weight.size()==price.size()

#include <vector>
#include <iostream>
#include <limits>

double sum(const std::vector<double>& v)
{
	double sum{0.0};
        for(const auto& val : v)
          sum += val;

	return sum;
}

static double max_v(const std::vector<double>& v)
{
	double max{0.0};

	for(const auto& val : v)
		if(val > max)
			max = val;

	return max;
}

double min_v(const std::vector<double>& v)
{
	double min_num{std::numeric_limits<double>::max()};
	for(const auto& val : v)
		if(val < min_num)
			min_num = val;

	return min_num;
}

//mean значит среднее
double mean(const std::vector<double>& v)
{
	return (sum(v)/v.size());
}

double median(const std::vector<double>& v)
{
	return v.at((v.size()-1)/2);
}

struct metrics
{
	double max_n;
	double min_n;
	double sum_n;
	double mean_n;
	double median_n;

	metrics()=default;

	metrics(const double& max, const double& min, const double& sum,
		const double& mean, const double& median)
	{
		this->max_n = max;
		this->min_n = min;
		this->sum_n = sum;
		this->mean_n = mean;
		this->median_n = median;
	}

	static metrics find_all(const std::vector<double>& v)
	{
		metrics res{};

		res.sum_n=sum(v);
		res.min_n=min_v(v);
		res.max_n=max_v(v);
		res.mean_n=mean(v);
		res.median_n=median(v);

		return res;
	}
};



int main()
{
	std::vector<double> price{1,2,3,4,5,6,7,8,9};
    std::vector<double> weight{9,8,7,6,5,4,3,2,1};

	const metrics metrics_price = metrics::find_all(price);

	std::cout<< metrics_price.max_n << "\n"
	<< metrics_price.min_n << "\n"
	<< metrics_price.sum_n << "\n"
	<< metrics_price.mean_n << std::endl;
}