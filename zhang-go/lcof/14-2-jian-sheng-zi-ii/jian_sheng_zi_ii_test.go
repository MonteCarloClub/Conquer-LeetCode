package jian_sheng_zi_ii

import "testing"

func TestCuttingRope(t *testing.T) {
	key := 953271190
	if cuttingRope(120) != key {
		t.Errorf("Wrong Answer!")
	}
}
