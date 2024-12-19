declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @uniquePaths( i32 %r100, i32 %r102 ) {
bb1:
  %r188 = add i32 0, 0
  %r189 = add i32 0, 0
  %r190 = add i32 0, 0
  %r191 = add i32 0, 0
  %r192 = add i32 0, 0
  %r108 = alloca [ 9 x i32 ]
  %r193 = add i32 0, 0
  %r194 = add i32 %r100, 0
  %r195 = add i32 0, 0
  %r196 = add i32 %r102, 0
  %r105 = icmp eq i32 %r194, 1
  br i1 %r105, label %bb_if_5_2_true, label %bb21_2_next

bb21_2_next:
  %r107 = icmp eq i32 %r196, 1
  br i1 %r107, label %bb_if_5_2_true, label %bb_if_5_2_false

bb_if_5_2_true:
  ret i32 1
bb_if_5_2_false:
  br label %bb_if_5_2_end

bb_if_5_2_end:
  %r197 = add i32 0, 0
  br label %bb_while_5_14_cond

bb_while_5_14_cond:
  %r198 = phi i32 [ %r190, %bb_if_5_2_end ], [ %r200, %bb_while_5_14_whilestms ]
  %r199 = phi i32 [ %r197, %bb_if_5_2_end ], [ %r201, %bb_while_5_14_whilestms ]
  %r116 = icmp slt i32 %r199, %r194
  br i1 %r116, label %bb_while_5_14_whilestms, label %bb_while_5_14_bre

bb_while_5_14_whilestms:
  %r118 = mul i32 %r199, 3
  %r120 = add i32 %r118, %r196
  %r121 = sub i32 %r120, 1
  %r200 = add i32 %r121, 0
  %r123 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r200
  store i32 1, i32* %r123
  %r125 = add i32 %r199, 1
  %r201 = add i32 %r125, 0
  br label %bb_while_5_14_cond

bb_while_5_14_bre:
  %r202 = add i32 0, 0
  br label %bb_while_5_20_cond

bb_while_5_20_cond:
  %r203 = phi i32 [ %r198, %bb_while_5_14_bre ], [ %r205, %bb_while_5_20_whilestms ]
  %r204 = phi i32 [ %r202, %bb_while_5_14_bre ], [ %r206, %bb_while_5_20_whilestms ]
  %r128 = icmp slt i32 %r204, %r196
  br i1 %r128, label %bb_while_5_20_whilestms, label %bb_while_5_20_bre

bb_while_5_20_whilestms:
  %r130 = sub i32 %r194, 1
  %r131 = mul i32 %r130, 3
  %r133 = add i32 %r131, %r204
  %r205 = add i32 %r133, 0
  %r135 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r205
  store i32 1, i32* %r135
  %r137 = add i32 %r204, 1
  %r206 = add i32 %r137, 0
  br label %bb_while_5_20_cond

bb_while_5_20_bre:
  %r139 = sub i32 %r194, 2
  %r207 = add i32 %r139, 0
  br label %bb_while_5_26_cond

bb_while_5_26_cond:
  %r208 = phi i32 [ %r191, %bb_while_5_20_bre ], [ %r214, %bb_while_9_28_bre ]
  %r209 = phi i32 [ %r203, %bb_while_5_20_bre ], [ %r215, %bb_while_9_28_bre ]
  %r210 = phi i32 [ %r189, %bb_while_5_20_bre ], [ %r216, %bb_while_9_28_bre ]
  %r211 = phi i32 [ %r188, %bb_while_5_20_bre ], [ %r217, %bb_while_9_28_bre ]
  %r212 = phi i32 [ %r207, %bb_while_5_20_bre ], [ %r222, %bb_while_9_28_bre ]
  %r141 = icmp sgt i32 %r212, -1
  br i1 %r141, label %bb_while_5_26_whilestms, label %bb_while_5_26_bre

bb_while_5_26_whilestms:
  %r143 = sub i32 %r196, 2
  %r213 = add i32 %r143, 0
  br label %bb_while_9_28_cond

bb_while_9_28_cond:
  %r214 = phi i32 [ %r213, %bb_while_5_26_whilestms ], [ %r221, %bb_while_9_28_whilestms ]
  %r215 = phi i32 [ %r209, %bb_while_5_26_whilestms ], [ %r218, %bb_while_9_28_whilestms ]
  %r216 = phi i32 [ %r210, %bb_while_5_26_whilestms ], [ %r219, %bb_while_9_28_whilestms ]
  %r217 = phi i32 [ %r211, %bb_while_5_26_whilestms ], [ %r220, %bb_while_9_28_whilestms ]
  %r145 = icmp sgt i32 %r214, -1
  br i1 %r145, label %bb_while_9_28_whilestms, label %bb_while_9_28_bre

bb_while_9_28_whilestms:
  %r147 = mul i32 %r212, 3
  %r149 = add i32 %r147, %r214
  %r218 = add i32 %r149, 0
  %r151 = add i32 %r212, 1
  %r152 = mul i32 %r151, 3
  %r154 = add i32 %r152, %r214
  %r219 = add i32 %r154, 0
  %r156 = mul i32 %r212, 3
  %r158 = add i32 %r156, %r214
  %r159 = add i32 %r158, 1
  %r220 = add i32 %r159, 0
  %r161 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r218
  %r163 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r219
  %r164 = load i32, i32* %r163
  %r166 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 %r220
  %r167 = load i32, i32* %r166
  %r168 = add i32 %r164, %r167
  store i32 %r168, i32* %r161
  %r170 = sub i32 %r214, 1
  %r221 = add i32 %r170, 0
  br label %bb_while_9_28_cond

bb_while_9_28_bre:
  %r172 = sub i32 %r212, 1
  %r222 = add i32 %r172, 0
  br label %bb_while_5_26_cond

bb_while_5_26_bre:
  %r173 = getelementptr [9 x i32 ], [9 x i32 ]* %r108, i32 0, i32 0
  %r174 = load i32, i32* %r173
  ret i32 %r174
}

define i32 @main( ) {
bb2:
  call void @_sysy_starttime(i32 40)
  %r225 = add i32 0, 0
  %r226 = add i32 0, 0
  %r227 = add i32 3, 0
  %r179 = call i32 @uniquePaths(i32 %r227, i32 %r227)
  %r228 = add i32 %r179, 0
  call void @_sysy_stoptime(i32 45)
  ret i32 %r228
}

