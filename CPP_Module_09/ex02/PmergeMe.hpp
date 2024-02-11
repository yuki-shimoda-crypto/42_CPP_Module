#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>
#include <sys/time.h>

class CommandLineParser {
public:
  CommandLineParser(const int argc, const char *argv[]);
  ~CommandLineParser();

  const std::vector<long> &getVector() const;
  const std::list<long> &getList() const;

private:
  std::vector<long> _numVec;
  std::list<long> _numList;

  void parseArgument(const int argc, const char *argv[]);

  void handleEmptyInput() const;
  void handleInvalidInput(const std::string &str) const;
  void handleMinusValue(const std::string &str) const;

  CommandLineParser();
  CommandLineParser(const CommandLineParser &parser);
  CommandLineParser &operator=(const CommandLineParser &parser);
};

template <typename Container> class MergeInsertionSort {
public:
  MergeInsertionSort(){};
  virtual ~MergeInsertionSort(){};

  void displayInput(const Container &container) const {
    displayContainer("before:\t", container);
  };

  void displayOutput(const Container &container) const {
    displayContainer("after:\t", container);
  };

  std::size_t sortAndMeasure(Container &container){
    struct timeval start, end;

    gettimeofday(&start, NULL);
    sort(container);
    (void)(container);
    gettimeofday(&end, NULL);

    std::size_t second = end.tv_sec - start.tv_sec;
    std::size_t micoro = (second * 1000000) + (end.tv_usec - start.tv_usec);
    return (micoro);
  };

  void displayTime(Container &container, std::string str, std::size_t time) {
    std::cout << "Time to process a range of " << container.size()
              << " elements with " << str << " : " << time << " us"
              << std::endl;
  };

protected:
    virtual void sort(Container &container) = 0;
    MergeInsertionSort(const MergeInsertionSort &sort){(void)sort;};

private:
  void displayContainer(const std::string &prefix,
                        const Container &container) const {
    std::cout << prefix;
    if (container.size() <= 5) {
      for (unsigned long i = 0; i < container.size(); i++) {
        std::cout << container.at(i) << ' ';
      }
      std::cout << std::endl;
    } else {
      for (unsigned long i = 0; i < 4; i++) {
        std::cout << container.at(i) << ' ';
      }
      std::cout << "[...]" << std::endl;
    }
  };

  MergeInsertionSort &operator=(const MergeInsertionSort &sort){};
};

class VectorMergeInsertionSort : public MergeInsertionSort<std::vector<long> > {
public:
  VectorMergeInsertionSort();
  ~VectorMergeInsertionSort();

private:
  void sort(std::vector<long> &container);

  VectorMergeInsertionSort(const VectorMergeInsertionSort &sort);
  VectorMergeInsertionSort &operator=(const VectorMergeInsertionSort &sort);
};


class ListMergeInsertionSort : public MergeInsertionSort<std::list<long> > {
public:
  ListMergeInsertionSort();
  ~ListMergeInsertionSort();

private:
  void sort(std::list<long> &container);

  ListMergeInsertionSort(const ListMergeInsertionSort &sort);
  ListMergeInsertionSort &operator=(const ListMergeInsertionSort &sort);
};

#endif
