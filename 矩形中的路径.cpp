struct AnchorNode {
	int m_covered_dirs[4];
	int m_pos_matrix;
	int m_pos_match;
};

class Solution {
public:
	// 非递归实现
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		int iLenStr = strlen(str);
		int iLenMatrix = strlen(matrix);

		// assert from length
		if (iLenStr > iLenMatrix || iLenStr <= 0) {
			return false;
		}

		// vector for saving all postions of the first character in str
		vector<int> vec_position_of_first_char;

		// find out all positions of the first character in str
		for (int i = 0; i < iLenMatrix; i++) {
			if (matrix[i] == str[0]) {
				vec_position_of_first_char.push_back(i);
			}
		}

		int nFirstCharCnt = vec_position_of_first_char.size();

		// check total count of the first character
		if (nFirstCharCnt <= 0) {
			return false;
		}

		if (iLenStr == 1) {
			return true;
		}

		// stack for saving traced nodes
		stack<AnchorNode> stkAnchorNodes;

		// quick mark for traced nodes
		vector<int> vecAnchorNodesMark(iLenMatrix, 0);

		// index of character in str, here initialed by 1 because the first character has been matched.
		int iIndexForMatching = 1;

		// scan all the positions of first character
		for (int iterOfFirstChar = 0; iterOfFirstChar < nFirstCharCnt; iterOfFirstChar++) {
			AnchorNode an;
			an.m_pos_matrix = vec_position_of_first_char[iterOfFirstChar];
			an.m_pos_match = iIndexForMatching;
			an.m_covered_dirs[0] = 0;
			an.m_covered_dirs[1] = 0;
			an.m_covered_dirs[2] = 0;
			an.m_covered_dirs[3] = 0;

			while (true) {
				int cur_match = an.m_pos_match;
				int cur_matrix = an.m_pos_matrix;
				int cur_x = cur_matrix % cols;
				int cur_y = cur_matrix / cols;

				// right
				if (cur_x < (cols - 1)
					&& vecAnchorNodesMark[cur_matrix + 1] == 0
					&& an.m_covered_dirs[0] == 0) {
					if (str[cur_match] == matrix[cur_matrix + 1]) {
						if (cur_match + 1 == iLenStr) {
							return true;
						}

						// save current postion
						vecAnchorNodesMark[cur_matrix] = 1;
						an.m_covered_dirs[0] = 1;
						stkAnchorNodes.push(an);

						// set new postion
						an.m_pos_match += 1;
						an.m_pos_matrix += 1;
						an.m_covered_dirs[0] = 0;
						an.m_covered_dirs[1] = 0;
						an.m_covered_dirs[2] = 1;
						an.m_covered_dirs[3] = 0;
						continue;
					}
					else {
						an.m_covered_dirs[0] = 1;
					}
				} // right

				// down
				if (cur_y < (rows - 1)
					&& vecAnchorNodesMark[(cur_y + 1) * cols + cur_x] == 0
					&& an.m_covered_dirs[1] == 0) {
					if (str[cur_match] == matrix[(cur_y + 1) * cols + cur_x]) {
						if (cur_match + 1 == iLenStr) {
							return true;
						}

						// save current postion
						vecAnchorNodesMark[cur_matrix] = 1;
						an.m_covered_dirs[1] = 1;
						stkAnchorNodes.push(an);

						// set new postion
						an.m_pos_match += 1;
						an.m_pos_matrix = (cur_y + 1) * cols + cur_x;
						an.m_covered_dirs[0] = 0;
						an.m_covered_dirs[1] = 0;
						an.m_covered_dirs[2] = 0;
						an.m_covered_dirs[3] = 1;
						continue;
					}
					else {
						an.m_covered_dirs[0] = 1;
					}
				} // down

				// left
				if (cur_x > 0
					&& vecAnchorNodesMark[cur_matrix - 1] == 0
					&& an.m_covered_dirs[2] == 0) {
					if (str[cur_match] == matrix[cur_matrix - 1]) {
						if (cur_match + 1 == iLenStr) {
							return true;
						}

						// save current postion
						vecAnchorNodesMark[cur_matrix] = 1;
						an.m_covered_dirs[2] = 1;
						stkAnchorNodes.push(an);

						// set new postion
						an.m_pos_match += 1;
						an.m_pos_matrix = cur_matrix - 1;
						an.m_covered_dirs[0] = 1;
						an.m_covered_dirs[1] = 0;
						an.m_covered_dirs[2] = 0;
						an.m_covered_dirs[3] = 0;
						continue;
					}
					else {
						an.m_covered_dirs[0] = 1;
					}
				} // left

				// up
				if (cur_y > 0
					&& vecAnchorNodesMark[(cur_y - 1 )* cols + cur_x] == 0
					&& an.m_covered_dirs[3] == 0) {
					if (str[cur_match] == matrix[(cur_y - 1)* cols + cur_x]) {
						if (cur_match + 1 == iLenStr) {
							return true;
						}

						// save current postion
						vecAnchorNodesMark[cur_matrix] = 1;
						an.m_covered_dirs[3] = 1;
						stkAnchorNodes.push(an);

						// set new postion
						an.m_pos_match += 1;
						an.m_pos_matrix = (cur_y - 1)* cols + cur_x;
						an.m_covered_dirs[0] = 0;
						an.m_covered_dirs[1] = 1;
						an.m_covered_dirs[2] = 0;
						an.m_covered_dirs[3] = 0;
						continue;
					}
					else {
						an.m_covered_dirs[0] = 1;
					}
				} // up

				// pop stack
				if (stkAnchorNodes.empty()) {
					break;
				}

				an = stkAnchorNodes.top();
				stkAnchorNodes.pop();
				vecAnchorNodesMark[an.m_pos_matrix] = 0;

				//if (stkAnchorNodes.empty()) {
				//	break;
				//}
			} // while (true)

		} // for (int iterOfFirstChar = 0; iterOfFirstChar < nFirstCharCnt; iterOfFirstChar++)
		return false;
	}
};
