-- final-dynamic-acc to edit-easy-dynami-acc
-- �ŏI�I�ȓ�����������ҏW���₷����������

NUMF = GetNumFrame(0) / 3

-- act00
for AID = 0, 7 do
  for FID = NUMF, NUMF*3-1 do
    DelFrame(AID, NUMF)
  end
end

-- act02
for AID = 16, 23 do
  for FID = NUMF, NUMF*3-1 do
    DelFrame(AID, NUMF)
  end
end
