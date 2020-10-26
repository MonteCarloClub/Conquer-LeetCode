package median_of_two_sorted_arrays

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	return float64(median(nums1, 0, len(nums1), nums2, 0, len(nums2)))
}

func median(n1 []int, lo1 int, len1 int, n2 []int, lo2 int, len2 int) float64 {
	if len1 > len2 {
		return median(n2, lo2, len2, n1, lo1, len1)
	}
	// 递归基
	if len1 < 3 || len2 < 3 {
		n := []int{}
		r1 := lo1
		r2 := lo2
		for r1 < lo1+len1 || r2 < lo2+len2 {
			if r1 == lo1+len1 {
				n = append(n, n2[r2:lo2+len2]...)
				break
			}
			if r2 == lo2+len2 {
				n = append(n, n1[r1:lo1+len1]...)
				break
			}
			if n1[r1] <= n2[r2] {
				n = append(n, n1[r1])
				r1++
			} else {
				n = append(n, n2[r2])
				r2++
			}
		}
		if len(n)%2 == 0 {
			return float64(n[len(n)/2-1]+n[len(n)/2]) / 2
		}
		return float64(n[len(n)/2])
	}

	if len1*2 < len2 {
		return median(n1, lo1, len1, n2, lo2+(len2-len1-1)/2, len1-(len2-len1)%2+2)
	}

	mi1 := lo1 + len1/2
	mi21 := lo2 + (len1-1)/2
	mi22 := lo2 - len1/2 + len2 - 1
	if n1[mi1] > n2[mi22] {
		return median(n1, lo1, len1/2+1, n2, mi21, len2-(len1-1)/2) /* n1左半，n2右半 */
	} else if n1[mi1] < n2[mi21] {
		return median(n1, mi1, (len1+1)/2, n2, lo2, len2-len1/2) /* n1右半，n2左半 */
	} else {
		return median(n1, lo1, len1, n2, mi21, len2-(len1-1)/2*2) /* n1全体，n2中间 */
	}
}
