package main

import (
	"fmt"
	"math"
)

type ErrNegativeSqrt float64

func (e ErrNegativeSqrt) Error() string {
	return fmt.Sprintf("cannot Sqrt negative number: %v", float64(e))
}

func Sqrt(x float64) (float64, error) {
	if x < 0 {
		return 0, ErrNegativeSqrt(x)
	}
	z := 1.0
	prev_z := z
	i := 0
	for ; i < 30; i++ {
		z -= (z*z - x) / (2 * z)
		if math.Abs(z-prev_z) < 0.00000001 {
			break
		}
		prev_z = z
	}
	return z, nil
}

func main() {
	fmt.Println(Sqrt(2))
	fmt.Println(Sqrt(-2))
}
