#pragma once
#include <string>
#include <unordered_set>
#include <vector>

class Solve {
public:
  // std::string Final = "";
  //
  // Solve(std::vector<std::string>& Object)
  // {
  //     const size_t TotalRows = Object.size();
  //
  //     size_t StartRow = 0;
  //     size_t StartColumn = 0;
  //     bool FoundStart = false;
  //
  //     for (size_t RowIndex = 0; RowIndex < TotalRows; ++RowIndex)
  //     {
  //         const size_t RowLength = Object[RowIndex].size();
  //
  //         for (size_t ColumnIndex = 0; ColumnIndex < RowLength;
  //         ++ColumnIndex)
  //         {
  //             if (Object[RowIndex][ColumnIndex] == 'S')
  //             {
  //                 StartRow = RowIndex;
  //                 StartColumn = ColumnIndex;
  //                 FoundStart = true;
  //                 break;
  //             }
  //         }
  //
  //         if (FoundStart)
  //         {
  //             break;
  //         }
  //     }
  //
  //     long long SplitCount = 0;
  //     std::unordered_set<size_t> ActiveColumns;
  //
  //     if (FoundStart)
  //     {
  //         ActiveColumns.insert(StartColumn);
  //
  //         for (size_t RowIndex = StartRow + 1; RowIndex < TotalRows &&
  //         !ActiveColumns.empty(); ++RowIndex)
  //         {
  //             std::unordered_set<size_t> NextActiveColumns;
  //             const size_t RowLength = Object[RowIndex].size();
  //
  //             for (size_t ColumnIndex : ActiveColumns)
  //             {
  //                 if (ColumnIndex >= RowLength)
  //                 {
  //                     continue;
  //                 }
  //
  //                 char CellValue = Object[RowIndex][ColumnIndex];
  //
  //                 if (CellValue == '^')
  //                 {
  //                     ++SplitCount;
  //
  //                     if (ColumnIndex > 0)
  //                     {
  //                         NextActiveColumns.insert(ColumnIndex - 1);
  //                     }
  //
  //                     if (ColumnIndex + 1 < RowLength)
  //                     {
  //                         NextActiveColumns.insert(ColumnIndex + 1);
  //                     }
  //                 }
  //                 else
  //                 {
  //                     NextActiveColumns.insert(ColumnIndex);
  //                 }
  //             }
  //
  //             ActiveColumns = std::move(NextActiveColumns);
  //         }
  //     }
  //
  //     Final = std::to_string(SplitCount);
  // }
  std::string Final = "0";

  Solve(std::vector<std::string> &Object) {
    const size_t TotalRows = Object.size();

    size_t StartRow = 0;
    size_t StartColumn = 0;
    bool FoundStart = false;

    for (size_t RowIndex = 0; RowIndex < TotalRows; ++RowIndex) {
      const size_t RowLength = Object[RowIndex].size();

      for (size_t ColumnIndex = 0; ColumnIndex < RowLength; ++ColumnIndex) {
        if (Object[RowIndex][ColumnIndex] == 'S') {
          StartRow = RowIndex;
          StartColumn = ColumnIndex;
          FoundStart = true;
          break;
        }
      }

      if (FoundStart) {
        break;
      }
    }

    long long TotalTimelines = 0;

    if (FoundStart) {
      size_t CurrentRowIndex = StartRow + 1;

      if (CurrentRowIndex >= TotalRows) {
        TotalTimelines = 1;
      } else {
        size_t CurrentRowLength = Object[CurrentRowIndex].size();
        std::vector<long long> CurrentTimelines(CurrentRowLength, 0);

        if (StartColumn < CurrentRowLength) {
          CurrentTimelines[StartColumn] = 1;
        } else {
          TotalTimelines = 1;
        }

        while (CurrentRowIndex < TotalRows && !CurrentTimelines.empty()) {
          const size_t RowLength = Object[CurrentRowIndex].size();
          size_t NextRowIndex = CurrentRowIndex + 1;
          size_t NextRowLength =
              NextRowIndex < TotalRows ? Object[NextRowIndex].size() : 0;
          std::vector<long long> NextTimelines(NextRowLength, 0);

          for (size_t ColumnIndex = 0; ColumnIndex < RowLength; ++ColumnIndex) {
            long long Ways = CurrentTimelines[ColumnIndex];
            if (Ways == 0) {
              continue;
            }

            char CellValue = Object[CurrentRowIndex][ColumnIndex];

            if (CellValue == '^') {
              bool HasNextRow = NextRowIndex < TotalRows;

              if (ColumnIndex > 0 && HasNextRow &&
                  ColumnIndex - 1 < NextRowLength) {
                NextTimelines[ColumnIndex - 1] += Ways;
              } else {
                TotalTimelines += Ways;
              }

              if (ColumnIndex + 1 < RowLength && HasNextRow &&
                  ColumnIndex + 1 < NextRowLength) {
                NextTimelines[ColumnIndex + 1] += Ways;
              } else {
                TotalTimelines += Ways;
              }
            } else {
              bool HasNextRow = NextRowIndex < TotalRows;

              if (HasNextRow && ColumnIndex < NextRowLength) {
                NextTimelines[ColumnIndex] += Ways;
              } else {
                TotalTimelines += Ways;
              }
            }
          }

          CurrentRowIndex = NextRowIndex;
          CurrentTimelines = std::move(NextTimelines);
        }
      }
    }

    Final = std::to_string(TotalTimelines);
  }
};
