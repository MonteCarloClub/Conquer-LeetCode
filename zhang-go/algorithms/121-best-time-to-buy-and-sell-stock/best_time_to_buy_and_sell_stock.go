package best_time_to_buy_and_sell_stock

func maxProfit(prices []int) int {
	priceMin := prices[0]
	result := 0
	for _, price := range prices {
		if price < priceMin {
			priceMin = price
		} else if price-priceMin > result {
			result = price - priceMin
		}
	}
	return result
}
