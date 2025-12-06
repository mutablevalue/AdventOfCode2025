#include <algorithm>
#include <string>
#include <vector>

class Solve {
public:
  // std::string Final;
  //
  // Solve(std::vector<std::string> &Object) {
  //   long long sum = 0;
  //
  //   int TotalRows = (int)Object.size();
  //   if (TotalRows == 0) {
  //     Final = "0";
  //     return;
  //   }
  //
  //   int OperatorRow = -1;
  //   for (int r = TotalRows - 1; r >= 0; --r) {
  //     if (Object[r].find('+') != std::string::npos ||
  //         Object[r].find('*') != std::string::npos) {
  //       OperatorRow = r;
  //       break;
  //     }
  //   }
  //   if (OperatorRow == -1) {
  //     Final = "0";
  //     return;
  //   }
  //
  //   int columns = 0;
  //   for (auto &line : Object)
  //     columns = std::max(columns, (int)line.size());
  //
  //   for (auto &line : Object)
  //     if ((int)line.size() < columns)
  //       line.append(columns - line.size(), ' ');
  //
  //   auto isSeparatorColumn = [&](int col) {
  //     for (int r = 0; r <= OperatorRow; r++)
  //       if (Object[r][col] != ' ')
  //         return false;
  //     return true;
  //   };
  //
  //   std::vector<long long> ColumnToManipulate;
  //   std::string OperatorToUse;
  //
  //   int CurrentColumn = 0;
  //   while (CurrentColumn < columns) {
  //     while (CurrentColumn < columns && isSeparatorColumn(CurrentColumn))
  //       CurrentColumn++;
  //
  //     if (CurrentColumn >= columns)
  //       break;
  //
  //     int StartColumn = CurrentColumn;
  //     while (CurrentColumn < columns && !isSeparatorColumn(CurrentColumn))
  //       CurrentColumn++;
  //     int EndColumn = CurrentColumn;
  //
  //     ColumnToManipulate.clear();
  //     OperatorToUse.clear();
  //
  //     for (int CurrentRow = 0; CurrentRow < OperatorRow; CurrentRow++) {
  //       std::string cell =
  //           Object[CurrentRow].substr(StartColumn, EndColumn - StartColumn);
  //       auto first = cell.find_first_not_of(' ');
  //       if (first == std::string::npos)
  //         continue;
  //       auto last = cell.find_last_not_of(' ');
  //       std::string token = cell.substr(first, last - first + 1);
  //       ColumnToManipulate.push_back(std::stoll(token));
  //     }
  //
  //     std::string OperatorCell =
  //         Object[OperatorRow].substr(StartColumn, EndColumn - StartColumn);
  //     for (char c : OperatorCell) {
  //       if (c == '+' || c == '*') {
  //         OperatorToUse.assign(1, c);
  //         break;
  //       }
  //     }
  //
  //     if (OperatorToUse == "+") {
  //       long long TempResult = 0;
  //       for (long long v : ColumnToManipulate)
  //         TempResult += v;
  //       sum += TempResult;
  //     } else if (OperatorToUse == "*") {
  //       long long TempResult = 1;
  //       for (long long v : ColumnToManipulate)
  //         TempResult *= v;
  //       sum += TempResult;
  //     }
  //   }
  //
  //   Final = std::to_string(sum);
  // }
  std::string Final;

  Solve(std::vector<std::string> &Object) {
    long long sum = 0;

    int TotalRows = (int)Object.size();
    if (TotalRows == 0) {
      Final = "0";
      return;
    }

    int OperatorRow = -1;
    for (int r = TotalRows - 1; r >= 0; --r) {
      if (Object[r].find('+') != std::string::npos ||
          Object[r].find('*') != std::string::npos) {
        OperatorRow = r;
        break;
      }
    }
    if (OperatorRow == -1) {
      Final = "0";
      return;
    }

    int columns = 0;
    for (auto &line : Object)
      columns = std::max(columns, (int)line.size());

    for (auto &line : Object)
      if ((int)line.size() < columns)
        line.append(columns - line.size(), ' ');

    auto isSeparatorColumn = [&](int col) {
      for (int r = 0; r <= OperatorRow; r++)
        if (Object[r][col] != ' ')
          return false;
      return true;
    };

    std::vector<long long> ColumnToManipulate;
    std::string OperatorToUse;

    int CurrentColumn = 0;
    while (CurrentColumn < columns) {
      while (CurrentColumn < columns && isSeparatorColumn(CurrentColumn))
        CurrentColumn++;

      if (CurrentColumn >= columns)
        break;

      int StartColumn = CurrentColumn;
      while (CurrentColumn < columns && !isSeparatorColumn(CurrentColumn))
        CurrentColumn++;
      int EndColumn = CurrentColumn;

      ColumnToManipulate.clear();
      OperatorToUse.clear();

      for (int col = StartColumn; col < EndColumn; ++col) {
        std::string digits;
        for (int row = 0; row < OperatorRow; ++row) {
          char ch = Object[row][col];
          if (ch >= '0' && ch <= '9')
            digits.push_back(ch);
        }
        if (!digits.empty())
          ColumnToManipulate.push_back(std::stoll(digits));
      }

      std::string OperatorCell =
          Object[OperatorRow].substr(StartColumn, EndColumn - StartColumn);
      for (char c : OperatorCell) {
        if (c == '+' || c == '*') {
          OperatorToUse.assign(1, c);
          break;
        }
      }

      if (OperatorToUse == "+") {
        long long TempResult = 0;
        for (long long v : ColumnToManipulate)
          TempResult += v;
        sum += TempResult;
      } else if (OperatorToUse == "*") {
        long long TempResult = 1;
        for (long long v : ColumnToManipulate)
          TempResult *= v;
        sum += TempResult;
      }
    }

    Final = std::to_string(sum);
  }
};
