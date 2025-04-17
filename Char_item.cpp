Search : if (Cell.IsEquipPosition() && !CanUnequipNow(item))

Add :
#ifdef ENABLE_FIX_BOW_EXPLOIT

	if (GetWear(WEAR_WEAPON) && GetQuestFlag("stop_spam_with_skill") && get_global_time() < GetQuestFlag("stop_spam_with_skill"))
	{
		ChatInfoTrans(("In %d sec you will can unequip your items."), (GetQuestFlag("stop_spam_with_skill") - get_global_time()) % 60);
		return false;
	}
#endif 

Search : bool CHARACTER::UnequipItem(LPITEM item)

Search: 	
	if (false == CanUnequipNow(item))
		return false;

Add :
#ifdef ENABLE_FIX_BOW_EXPLOIT
	 if (GetWear(WEAR_WEAPON) && GetQuestFlag("stop_spam_with_skill") && get_global_time() < GetQuestFlag("stop_spam_with_skill"))
	 {
		ChatInfoTrans(("In %d sec you will can unequip your items."), (GetQuestFlag("stop_spam_with_skill") - get_global_time()) % 60);

		 
		return false;
	 }
	
#endif
