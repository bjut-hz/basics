package bestTimeToBuyAndSellStockWithCooldown


import (
	"testing"
	"fmt"
)

func TestBestTime(t *testing.T) {
	prices := []int{1,2,3,0,2}
	fmt.Println(maxProfit(prices))
}