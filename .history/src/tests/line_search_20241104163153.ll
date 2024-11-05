declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
bb1:
  %r142 = add i32 0, 0
  %r143 = add i32 0, 0
  %r144 = add i32 0, 0
  %r145 = add i32 0, 0
  %r146 = add i32 0, 0
  %r147 = add i32 0, 0
  %r148 = add i32 0, 0
  call void @_sysy_starttime(i32 3)
  %r149 = add i32 0, 0
  %r150 = add i32 0, 0
  %r102 = alloca [ 10 x i32 ]
  %r151 = add i32 0, 0
  %r152 = add i32 0, 0
  br label %bb2

bb2:
  %r153 = phi i32 [ %r152, %bb1 ], [ %r187, %bb3 ]
  %r154 = icmp slt i32 %r153, 10
  br i1 %r154, label %bb3, label %bb4

bb3:
  %r184 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r153
  %r185 = add i32 %r153, 1
  store i32 %r185, i32* %r184
  %r186 = add i32 %r153, 1
  %r187 = add i32 %r186, 0
  br label %bb2

bb4:
  %r155 = add i32 10, 0
  %r156 = call i32 @getint()
  %r157 = add i32 %r156, 0
  %r158 = sub i32 %r155, 1
  %r159 = add i32 %r158, 0
  %r160 = add i32 0, 0
  %r161 = add i32 %r159, %r160
  %r162 = sdiv i32 %r161, 2
  %r163 = add i32 %r162, 0
  %r164 = add i32 0, 0
  %r165 = add i32 0, 0
  %r166 = add i32 0, 0
  br label %bb5

bb5:
  %r167 = phi i32 [ %r164, %bb4 ], [ %r178, %bb10 ]
  %r168 = phi i32 [ %r165, %bb4 ], [ %r181, %bb10 ]
  %r169 = phi i32 [ %r166, %bb4 ], [ %r179, %bb10 ]
  %r170 = icmp slt i32 %r168, 10
  br i1 %r170, label %bb8, label %bb7

bb8:
  %r174 = icmp eq i32 %r167, 0
  br i1 %r174, label %bb6, label %bb7

bb6:
  %r175 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r168
  %r176 = load i32, i32* %r175
  %r177 = icmp eq i32 %r176, %r157
  br i1 %r177, label %bb9, label %bb10

bb9:
  %r182 = add i32 1, 0
  %r183 = add i32 %r168, 0
  br label %bb10

bb10:
  %r178 = phi i32 [ %r167, %bb6 ], [ %r182, %bb9 ]
  %r179 = phi i32 [ %r169, %bb6 ], [ %r183, %bb9 ]
  %r180 = add i32 %r168, 1
  %r181 = add i32 %r180, 0
  br label %bb5

bb7:
  %r171 = icmp eq i32 %r167, 1
  br i1 %r171, label %bb11, label %bb12

bb11:
  call void @putint(i32* %r169)
  br label %bb13

bb12:
  %r173 = add i32 0, 0
  call void @putint(i32* %r173)
  br label %bb13

bb13:
  %r172 = add i32 10, 0
  call void @putch(i32* %r172)
  call void @_sysy_stoptime(i32 53)
  ret i32 0
}

